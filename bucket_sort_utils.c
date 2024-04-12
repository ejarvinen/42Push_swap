/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:17:36 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 08:31:28 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
locates a node in a linked list according to given index
*/
t_list	*find_node(t_list **lst, int index)
{
	t_list	*node;

	node = *lst;
	while (index > 0)
	{
		node = node->next;
		index--;
	}
	return (node);
}

/*
fills list big_three with the three largest indexes from stack
*/
void	get_max_three(t_list **stack, t_list **big_three)
{
	t_list	*new_node;
	int		max;

	max = find_max(stack);
	new_node = ft_lstnew("0");
	if (!new_node)
		*big_three = NULL;
	new_node->index = max;
	*big_three = new_node;
	while (ft_lstsize(*big_three) != 0 && ft_lstsize(*big_three) < 4)
	{
		max = find_next_largest(stack, big_three);
		new_node = ft_lstnew("0");
		if (new_node)
		{
			new_node->index = max;
			ft_lstadd_back(big_three, new_node);
		}
		else
			free_list(big_three);
	}
}

/*
fills list power_couple with the two largest indexes from stack
*/
int	get_two_largest(t_list **stack, t_list **power_couple)
{
	t_list	*new_node;
	int		max;

	max = find_max(stack);
	new_node = ft_lstnew("0");
	if (!new_node)
	{
		*power_couple = NULL;
		return (0);
	}
	new_node->index = max;
	*power_couple = new_node;
	if (*power_couple)
	{
		max = find_next_largest(stack, power_couple);
		new_node = ft_lstnew("0");
		if (new_node)
		{
			new_node->index = max;
			ft_lstadd_back(power_couple, new_node);
		}
		else
			free_list(power_couple);
	}
	return (1);
}

/*
finds the largest and second largest numbers and their locations in stack
*/
static void	set_specs_maxtwo(t_list **stack, t_list **power_couple,
t_opt *specs)
{
	t_list	*second;

	specs->max = find_max(power_couple);
	specs->max_index = find_node_location(stack, specs->max);
	second = *power_couple;
	second = second->next;
	specs->maxx = second->index;
	specs->maxx_index = find_node_location(stack, specs->maxx);
}

/*
finds the second largest number in stack and brings it on top if it's
contained in the same half as the largest number; otherwise brings
largest number on top
*/
void	bring_maxtwo_ontop(t_list **stack, t_list **power_couple, int c)
{
	int		midpoint;
	t_list	*head;
	t_opt	specs;

	if (is_descending(stack) == 0)
	{
		head = *stack;
		midpoint = ft_lstsize(head) / 2 + ft_lstsize(head) % 2;
		set_specs_maxtwo(stack, power_couple, &specs);
		if (specs.max_index > midpoint && specs.maxx_index > specs.max_index)
		{
			while (head->index != specs.maxx)
				reverse_rotate(&head, c);
			*stack = head;
		}
		else if (specs.max_index < midpoint
			&& specs.maxx_index < specs.max_index)
		{
			while (head->index != specs.maxx)
				rotate(&head, c);
			*stack = head;
		}
		else
			bring_max_ontop(stack, c);
	}
}
