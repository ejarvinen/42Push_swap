/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:39:02 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 10:11:00 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pushes from stack_a to stack_b and arranges stack_b accordingly
*/
void	push_to_b(t_list **stack_a, t_list **stack_b, t_sort *specs)
{
	t_list	*head_b;
	t_list	*next_b;

	push(stack_a, stack_b, 'b');
	specs->nodes_pushed++;
	if (specs->nodes_pushed > 1)
	{
		head_b = *stack_b;
		next_b = head_b->next;
		if (specs->len - ft_lstsize(*stack_b) > 120)
		{
			if (head_b->index <= ((specs->bucket * specs->bsize) / 2))
				rotate(stack_b, 'b');
			else if (head_b->index < next_b->index)
				swap(*stack_b, 'b');
		}
		else
		{
			if (head_b->index <= (((specs->len - 3) / 2
						+ specs->ssize / 2) / 2))
				rotate(stack_b, 'b');
			else if (head_b->index < next_b->index)
				swap(*stack_b, 'b');
		}
	}
}

/*
determines whether ra or rra is more economical
*/
void	update_bucket(t_list **stack_b, t_sort *specs)
{
	if (specs->len - ft_lstsize(*stack_b) > 120)
	{
		if (specs->nodes_pushed == specs->bucket * specs->bsize)
			specs->bucket++;
	}
	else
	{
		if (specs->nodes_pushed == (specs->len - 2) / 2
			+ specs->ssize / 2)
			specs->ssize = ft_lstsize(*stack_b);
	}
}

/*
rotates stack_a according to factor
*/
void	rotate_stack(t_list **stack_a, int *factor)
{
	int	rotations;

	rotations = 0;
	if (*factor > 0)
	{
		while (rotations < *factor)
		{
			rotate(stack_a, 'a');
			rotations++;
		}
	}
	else if (*factor < 0)
	{
		*factor = (-1) * (*factor);
		while (rotations < *factor)
		{
			reverse_rotate(stack_a, 'a');
			rotations++;
		}
	}
}
