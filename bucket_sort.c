/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:38:46 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 09:07:49 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
compares the first two elements of stack and swaps them
if they're not in the correct order
*/
void	arrange_stack(t_list **stack, int c)
{
	t_list	*head;
	t_list	*next;

	head = *stack;
	next = head->next;
	if (c == 'a')
	{
		if (head->index > next->index)
			swap(*stack, c);
	}
	else if (c == 'b')
	{
		if (head->index < next->index)
			swap(*stack, c);
	}
}

/*
pushes nodes from stack_b to stack_a 
*/
static int	fill_stack_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*power_couple;

	while (ft_lstsize(*stack_b) > 1)
	{
		get_two_largest(stack_b, &power_couple);
		if (power_couple == NULL)
			return (0);
		bring_maxtwo_ontop(stack_b, &power_couple, 'b');
		push(stack_b, stack_a, 'a');
		arrange_stack(stack_a, 'a');
		bring_max_ontop(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		arrange_stack(stack_a, 'a');
		free_list(&power_couple);
	}
	if (ft_lstsize(*stack_b))
		push(stack_b, stack_a, 'a');
	arrange_stack(stack_a, 'a');
	return (1);
}

/*
initializes values for bucket sort
*/
static void	initialize_specs(t_sort *specs, int len)
{
	specs->len = len;
	specs->bsize = 40;
	specs->bucket = 1;
	specs->ssize = 0;
	specs->nodes_pushed = 0;
}

/*
performs the best bucket sort ever
*/
int	bucket_sort(t_list **stack_a, t_list **stack_b, int len)
{
	t_list	*secret_stack;
	t_sort	sort_specs;

	secret_stack = NULL;
	get_max_three(stack_a, &secret_stack);
	if (!secret_stack)
		return (0);
	initialize_specs(&sort_specs, len);
	if (len > 120)
		empty_stack_a_big(stack_a, stack_b, &secret_stack, &sort_specs);
	else
		empty_stack_a_small(stack_a, stack_b, &secret_stack, &sort_specs);
	sort_three(stack_a);
	fill_stack_a(stack_a, stack_b);
	free_list(&secret_stack);
	return (1);
}
