/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:22:22 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 10:06:41 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
finds the largest value in stack according to index
*/
int	find_max(t_list **stack)
{
	int		max;
	t_list	*head;

	head = *stack;
	max = head->index;
	head = head->next;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	return (max);
}

/*
checks if given index can be found in linked list
*/
int	is_inlist(t_list **list, int node_index)
{
	t_list	*temp;
	int		len;
	int		index;

	len = ft_lstsize(*list);
	index = 0;
	temp = *list;
	while (index < len)
	{
		if (temp->index == node_index)
			return (1);
		temp = temp->next;
		index++;
	}
	return (0);
}

/*
finds the next largest index in stack that is not found in stash and returns it
*/
int	find_next_largest(t_list **stack, t_list **stash)
{
	int		max;
	t_list	*head;

	if (*stash == NULL)
		return (0);
	head = *stack;
	max = head->index;
	head = head->next;
	while (head)
	{
		if (head->index > max && is_inlist(stash, head->index) == 0)
			max = head->index;
		head = head->next;
	}
	return (max);
}

/* 
finds the largest number in stack and brings it on top
*/
void	bring_max_ontop(t_list **stack, int c)
{
	int		max;
	int		max_index;
	int		midpoint;
	t_list	*head;

	if (is_descending(stack) == 0)
	{
		head = *stack;
		max = find_max(stack);
		max_index = find_node_location(stack, max);
		midpoint = ft_lstsize(head) / 2 + ft_lstsize(head) % 2;
		if (max_index > midpoint)
		{
			while (head->index != max)
				reverse_rotate(&head, c);
		}
		else
		{
			while (head->index != max)
				rotate(&head, c);
		}
		*stack = head;
	}
}
