/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 07:59:06 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/24 16:04:09 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
swaps the first two items in stack
*/
void	swap(t_list *stack, int c)
{
	void	*temp;
	int		swp;
	t_list	*nextnode;

	if (stack)
	{
		if (ft_lstsize(stack) > 1)
		{
			nextnode = stack->next;
			temp = stack->content;
			swp = stack->index;
			stack->index = nextnode->index;
			nextnode->index = swp;
			stack->content = nextnode->content;
			nextnode->content = temp;
			if (c == 97)
				ft_putstr_fd("sa\n", 1);
			else if (c == 98)
				ft_putstr_fd("sb\n", 1);
			else
			{
			}
		}
	}
}

/*
performs swap operation for two stacks
*/
void	swap_both(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_putstr_fd("ss\n", 1);
}

/*
pushes from stack 'from' to stack 'to'
*/
void	push(t_list **from, t_list **to, int c)
{
	t_list	*src;

	if (*from)
	{
		src = *from;
		*from = src->next;
		ft_lstadd_front(to, src);
		if (c == 97)
			ft_putstr_fd("pa\n", 1);
		else if (c == 98)
			ft_putstr_fd("pb\n", 1);
	}
}

/*
rotates stack, first element becomes last one
*/
void	rotate(t_list **stack, int c)
{
	t_list	*temp;
	t_list	*next;

	temp = *stack;
	next = temp->next;
	*stack = next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	if (c == 97)
		ft_putstr_fd("ra\n", 1);
	else if (c == 98)
		ft_putstr_fd("rb\n", 1);
	else
	{
	}
}

/*
rotates two stacks
*/
void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}
