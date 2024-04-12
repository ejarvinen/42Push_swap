/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:30:58 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 08:59:56 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
compares the locations of the first and last indexes found in stack_a
that belong to the current bucket limits and returns the one that's
closest to either "end" of the stack. If the distance to both indexes
is equal, it returns the smaller one. rra is turned negative
*/
int	determine_factor(int ra, int rra, t_list **stack_a)
{
	t_list	*ra_node;
	t_list	*rra_node;

	rra = ft_lstsize(*stack_a) - rra;
	if (rra == ra)
	{
		ra_node = find_node(stack_a, ra);
		rra_node = find_node(stack_a, rra);
		if (rra_node->index < ra_node->index)
			return (-1 * rra);
		else
			return (ra);
	}
	else if (ra < rra && ra >= 0)
		return (ra);
	return (-1 * rra);
}

/*
finds the first index that belongs to the current bucket in the first half
of stack_a
*/
static int	ra_factor(t_list **stack_a, t_list **secret_stack,
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
			if (specs->ssize <= head->index
				&& head->index <= (specs->len - 3) / 2 + specs->ssize / 2)
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
static int	rra_factor(t_list **stack_a, t_list **secret_stack,
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
		if (specs->ssize <= head->index
			&& head->index <= (specs->len - 3) / 2 + specs->ssize / 2)
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
static int	rotate_stack_a(t_list **stack_a, t_list **secret_stack,
t_sort *specs)
{
	int	ra;
	int	rra;
	int	factor;

	ra = -1;
	ra = ra_factor(stack_a, secret_stack, specs);
	rra = rra_factor(stack_a, secret_stack, specs, &ra);
	factor = determine_factor(ra, rra, stack_a);
	return (factor);
}

/*
uses logarithmic bucket size to push numbers from stack_a to stack_b
*/
void	empty_stack_a_small(t_list **stack_a, t_list **stack_b,
t_list **secret_stack, t_sort *specs)
{
	t_list	*head;
	int		factor;

	while (specs->nodes_pushed < specs->len - 3)
	{
		head = *stack_a;
		if (specs->ssize <= head->index
			&& head->index <= (specs->len - 3) / 2 + specs->ssize / 2)
		{
			if (is_inlist(secret_stack, head->index) == 0)
			{
				push_to_b(stack_a, stack_b, specs);
				update_bucket(stack_b, specs);
			}
		}
		if (push_last_two(stack_a, stack_b) > 0)
			break ;
		factor = rotate_stack_a(stack_a, secret_stack, specs);
		rotate_stack(stack_a, &factor);
	}
}
