/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:50:37 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 09:03:52 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
counts how many substrings a 2D array contains
*/
int	substrlen(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

/*
checks whether stack is in ascending order
*/
int	is_ascending(t_list **stack)
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
		if (next < current)
			return (0);
		current = next;
	}
	return (1);
}

/*
compares the contents of the first node of list first to contents in list second
*/
static int	compare_lists(t_list *first, t_list *second, int len, int index)
{
	int	node_index;
	int	current;
	int	next;

	node_index = 0;
	current = ft_atoi(first->content);
	while (node_index < len)
	{
		next = ft_atoi(second->content);
		if (next == current && index != node_index)
			return (0);
		node_index++;
		second = second->next;
	}
	return (1);
}

/*
checks if stack_a contains nodes with duplicate content
*/
int	check_for_duplicates(t_list **stack_a)
{
	int		index;
	int		len;
	t_list	*list;
	t_list	*head;

	len = ft_lstsize(*stack_a);
	if (len < 2)
		return (1);
	index = 0;
	list = *stack_a;
	while (index < len)
	{
		head = *stack_a;
		if (compare_lists(list, head, len, index) == 0)
			return (0);
		index++;
		list = list->next;
	}
	return (1);
}
