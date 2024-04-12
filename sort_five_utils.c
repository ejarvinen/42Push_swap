/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:48:54 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 08:45:37 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
checks whether a stack is in descending order
*/
int	is_descending(t_list **stack)
{
	int		current;
	int		next;
	t_list	*head;

	if (ft_lstsize(*stack) < 1)
		return (1);
	head = *stack;
	current = head->index;
	while (head->next)
	{
		head = head->next;
		next = head->index;
		if (next > current)
			return (0);
		current = next;
	}
	return (1);
}

/*
finds the smallest index in a stack
*/
int	find_min(t_list **stack)
{
	int		index;
	t_list	*head;

	head = *stack;
	index = head->index;
	head = head->next;
	while (head)
	{
		if (head->index < index)
			index = head->index;
		head = head->next;
	}
	return (index);
}

/*
finds the next smallest number in stack by comparing to contents
in stash
*/
int	find_next_smallest(t_list **stack, t_list **stash)
{
	int		min;
	t_list	*head;

	if (*stash == NULL)
		return (0);
	head = *stack;
	min = head->index;
	head = head->next;
	while (head)
	{
		if (head->index < min && is_inlist(stash, head->index) == 0)
			min = head->index;
		head = head->next;
	}
	return (min);
}

/*
finds two smallest numbers in stack and saves them in double_trouble
*/
int	get_two_smallest(t_list **stack, t_list **double_trouble)
{
	t_list	*new_node;
	int		min;

	min = find_min(stack);
	new_node = ft_lstnew("0");
	if (!new_node)
	{
		*double_trouble = NULL;
		return (0);
	}
	new_node->index = min;
	*double_trouble = new_node;
	if (*double_trouble)
	{
		min = find_next_smallest(stack, double_trouble);
		new_node = ft_lstnew("0");
		if (new_node)
		{
			new_node->index = min;
			ft_lstadd_back(double_trouble, new_node);
		}
		else
			free_list(double_trouble);
	}
	return (1);
}

/*
finds the node placement in stack for given index
*/
int	find_node_location(t_list **stack, int index)
{
	int		location;
	t_list	*head;

	head = *stack;
	location = 0;
	while (head)
	{
		if (head->index == index)
			return (location);
		head = head->next;
		location++;
	}
	return (location);
}
