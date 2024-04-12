/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:05:13 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 08:39:22 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
finds the smallest number that doesn't have an index yet in stack
*/
int	idx_find_min(t_list *stack)
{
	int		min;
	t_list	*head;

	head = stack;
	while (head->index != -1)
		head = head->next;
	min = ft_atoi(head->content);
	head = stack;
	while (head)
	{
		if (ft_atoi(head->content) < min && head->index == -1)
			min = ft_atoi(head->content);
		head = head->next;
	}
	return (min);
}

/*
sets indexes for all the nodes in stack_a, smallest value gets index 0
*/
void	set_indexes(t_list **stack_a)
{
	int		index;
	int		min;
	int		len;
	t_list	*head;

	head = *stack_a;
	index = 0;
	len = ft_lstsize(head);
	while (index < len)
	{
		head = *stack_a;
		min = idx_find_min(head);
		while (ft_atoi(head->content) != min)
			head = head->next;
		head->index = index;
		index++;
	}
}
