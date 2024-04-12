/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:13:40 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 09:00:18 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
sorts a stack of size 3
*/
void	sort_three(t_list **stack)
{
	t_list	*next;
	t_list	*head;

	if (is_ascending(stack) == 0)
	{
		head = *stack;
		next = head->next;
		if (head->index > next->index)
			swap(*stack, 'a');
		if (is_ascending(stack) == 0)
		{
			reverse_rotate(stack, 'a');
			if (is_ascending(stack) == 0)
				swap(*stack, 'a');
		}
	}
}
