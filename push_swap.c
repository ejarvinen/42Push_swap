/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:53:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 10:37:03 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
converts 2D array to linked list (stack_a)
*/
int	build_stack(char **array, t_list **stack_a)
{
	t_list	*new_node;
	char	*str;
	int		index;

	index = 0;
	while (array[index])
	{
		str = ft_strdup(array[index]);
		if (!str)
			return (0);
		new_node = ft_lstnew(str);
		if (!new_node)
			return (0);
		new_node->index = -1;
		ft_lstadd_back(stack_a, new_node);
		index++;
	}
	return (index);
}

/*
sends stack_a and stack_b to different sorting functions according
to stack_a size
*/
static int	controller(t_list **stack_a)
{
	t_list	*stack_b;
	int		list_len;

	stack_b = NULL;
	list_len = ft_lstsize(*stack_a);
	if (list_len < 4)
		sort_three(stack_a);
	else if (list_len < 6)
		sort_five(stack_a, &stack_b);
	else
		bucket_sort(stack_a, &stack_b, list_len);
	if (is_ascending(stack_a) > 0 && ft_lstsize(stack_b) == 0)
		return (1);
	return (0);
}

/*
it's a main, what do you want me to tell you
*/
int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (0);
	if (ft_strlen(argv[1]) == 0)
		return (0);
	stack_a = input_validator(argv, &stack_a);
	if (stack_a)
	{
		set_indexes(&stack_a);
		if (is_ascending(&stack_a) > 0)
		{
			ft_lstclear(&stack_a, free);
			return (0);
		}
		if (controller(&stack_a) > 0)
		{
			ft_lstclear(&stack_a, free);
			return (0);
		}
		ft_lstclear(&stack_a, free);
	}
	ft_putendl_fd("Error", 2);
	return (1);
}
