/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 06:08:39 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 08:49:05 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
finds the smallest index in a stack and brings it on top
*/
void	bring_min_ontop(t_list **stack, int c)
{
	int		min;
	int		min_place;
	int		halfway;
	t_list	*head;

	if (is_ascending(stack) == 0)
	{
		head = *stack;
		min = find_min(stack);
		min_place = find_node_location(stack, min);
		halfway = ft_lstsize(head) / 2 + ft_lstsize(head) % 2;
		if (min_place > halfway)
		{
			while (head->index != min)
				reverse_rotate(&head, c);
		}
		else
		{
			while (head->index != min)
				rotate(&head, c);
		}
		*stack = head;
	}
}

/*
finds how many times stack_a needs to be rotated to bring one of
the two smallest numbers on top
*/
int	rafactor(t_list **stack_a, t_list **double_trouble)
{
	int		ra;
	int		halfway;
	t_list	*head;

	halfway = ft_lstsize(*stack_a) / 2 + ft_lstsize(*stack_a) % 2;
	ra = -1;
	head = *stack_a;
	while (halfway >= 0)
	{
		if (ra < 0)
		{
			if (is_inlist(double_trouble, head->index) == 1)
			{
				ra = find_node_location(stack_a, head->index);
				return (ra);
			}
		}
		halfway--;
		head = head->next;
	}
	return (ra);
}

/*
finds how many times stack_a needs to be reverse rotated to bring one of
the two smallest numbers on top
*/
int	rrafactor(t_list **stack_a, t_list **double_trouble, int *ra)
{
	int		rra;
	int		new;
	int		halfway;
	t_list	*head;

	halfway = ft_lstsize(*stack_a) / 2 + ft_lstsize(*stack_a) % 2;
	head = find_node(stack_a, halfway);
	rra = *ra;
	while (head)
	{
		if (is_inlist(double_trouble, head->index) == 1)
		{
			new = find_node_location(stack_a, head->index);
			if (new > rra)
				rra = new;
		}
		head = head->next;
	}
	return (rra);
}

/*
determines which direction stack_a is more economical to rotate
*/
int	rotate_stacka(t_list **stack_a, t_list **double_trouble)
{
	int	ra;
	int	rra;
	int	factor;

	ra = -1;
	ra = rafactor(stack_a, double_trouble);
	rra = rrafactor(stack_a, double_trouble, &ra);
	factor = determine_factor(ra, rra, stack_a);
	return (factor);
}

/*
sorts stack_a of size 5 in ascending order using stack_b
*/
void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (is_ascending(stack_a) == 0)
	{
		if (push_last_two(stack_a, stack_b) == 0)
		{
			bring_min_ontop(stack_a, 'a');
			push(stack_a, stack_b, 'b');
		}
		sort_three(stack_a);
		if (is_descending(stack_b) == 0)
			swap(*stack_b, 'b');
		while (ft_lstsize(*stack_b))
			push(stack_b, stack_a, 'a');
	}
}
