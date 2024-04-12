/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:05:14 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 10:00:21 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
reverse rotates stack, last element becomes first one
*/
void	reverse_rotate(t_list **stack, int c)
{
	t_list	*temp;
	t_list	*next;

	temp = *stack;
	next = temp->next;
	while (next->next)
	{
		temp = temp->next;
		next = next->next;
	}
	temp->next = NULL;
	ft_lstadd_front(stack, next);
	if (c == 97)
		ft_putstr("rra\n");
	else if (c == 98)
		ft_putstr("rrb\n");
	else
	{
	}
}

/*
reverse rotates two stacks
*/
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	ft_putstr("rrr\n");
}
