/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:03:04 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 09:09:48 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
pushes the last two nodes from stack_a tp stack_b leaving
3 nodes in stack_a
*/
int	push_last_two(t_list **stack_a, t_list **stack_b)
{
	t_list	*double_trouble;
	int		factor;

	if (ft_lstsize(*stack_a) == 5)
	{
		get_two_smallest(stack_a, &double_trouble);
		factor = rotate_stacka(stack_a, &double_trouble);
		rotate_stack(stack_a, &factor);
		push(stack_a, stack_b, 'b');
		if (ft_lstsize(*stack_b) > 1)
			arrange_stack(stack_b, 'b');
		bring_min_ontop(stack_a, 'a');
		push(stack_a, stack_b, 'b');
		free_list(&double_trouble);
		return (1);
	}
	return (0);
}

/*
finds the first index that belongs to the current bucket in the first half
of stack_a
*/
static int	ra_factor_big(t_list **stack_a, t_list **secret_stack,
t_sort *specs)
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
			if ((specs->bucket - 1) * specs->bsize <= head->index
				&& head->index < specs->bucket * specs->bsize)
			{
				if (is_inlist(secret_stack, head->index) == 0)
				{
					ra = find_node_location(stack_a, head->index);
					return (ra);
				}
			}
		}
		halfway--;
		head = head->next;
	}
	return (ra);
}

/*
finds the last index that belongs to the current bucket in the second half
of stack_a
*/
static int	rra_factor_big(t_list **stack_a, t_list **secret_stack,
t_sort *specs, int *ra)
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
		if ((specs->bucket - 1) * specs->bsize <= head->index
			&& head->index < specs->bucket * specs->bsize)
		{
			if (is_inlist(secret_stack, head->index) == 0)
			{
				new = find_node_location(stack_a, head->index);
				if (new > rra)
					rra = new;
			}
		}
		head = head->next;
	}
	return (rra);
}

/*
checks for both halves of stack_a for the cheapest index in the current
bucket to move and returns the number of moves required to move it
on top of stack_a in factor
*/
static int	rotate_stack_a_big(t_list **stack_a, t_list **secret_stack,
t_sort *specs)
{
	int	ra;
	int	rra;
	int	factor;

	ra = -1;
	ra = ra_factor_big(stack_a, secret_stack, specs);
	rra = rra_factor_big(stack_a, secret_stack, specs, &ra);
	factor = determine_factor(ra, rra, stack_a);
	return (factor);
}

/*
uses constant bucket size to push numbers from stack_a to stack_b
*/
void	empty_stack_a_big(t_list **stack_a, t_list **stack_b,
t_list **secret_stack, t_sort *specs)
{
	t_list	*head;
	int		factor;

	while (ft_lstsize(*stack_a) > 120)
	{
		head = *stack_a;
		if ((specs->bucket - 1) * specs->bsize <= head->index
			&& head->index < specs->bucket * specs->bsize)
		{
			if (is_inlist(secret_stack, head->index) == 0)
			{
				push_to_b(stack_a, stack_b, specs);
				update_bucket(stack_b, specs);
			}
		}
		factor = rotate_stack_a_big(stack_a, secret_stack, specs);
		rotate_stack(stack_a, &factor);
	}
	specs->ssize = find_min(stack_a);
	empty_stack_a_small(stack_a, stack_b, secret_stack, specs);
}
