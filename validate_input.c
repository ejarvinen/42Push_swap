/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 07:41:43 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 09:05:07 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
checks if given number in array format overflows
*/
static int	check_for_overflow(char *array)
{
	if ((array[0] == '-' && ft_atoi(array) >= 0) || (array[0] != '-'
			&& ft_atoi(array) < 0))
		return (0);
	return (1);
}

/*
checks if char array converted to int fullfills the requirements for an int
*/
static int	check_int(char *array)
{
	int	index;

	index = 0;
	while (array[index] != '\0')
	{
		if (ft_isdigit(array[index]) || (index == 0 && array[index] == '-')
			|| (index == 0 && array[index] == '+'))
			index++;
		else
			return (0);
	}
	return (1);
}

/*
checks if 2D array contains only numeric values that are MIN_INT - MAX_INT
*/
static int	check_for_int(char **array)
{
	int		index;

	index = 0;
	while (array[index])
	{
		if (check_int(array[index]) && check_for_overflow(array[index]) > 0)
			index++;
		else
			return (0);
	}
	return (1);
}

/*
checks if 2D array contains duplicate values
*/
static int	check_for_doubles(char **array)
{
	int	index;
	int	sub_str;

	if (substrlen(array) < 2)
		return (1);
	sub_str = 1;
	while (array[sub_str])
	{
		index = sub_str - 1;
		while (index >= 0)
		{
			if (ft_atoi(array[index]) == ft_atoi(array[sub_str]))
				return (0);
			index--;
		}
		sub_str++;
	}
	return (1);
}

/*
splits input into 2D array, checks that input contains ints only
and no duplicate values, then converts it to linked list
*/
t_list	*input_validator(char **argv, t_list **stack_a)
{
	char	**array;
	int		index;

	index = 1;
	while (argv[index])
	{
		array = ft_split(argv[index], ' ');
		if (!array)
			return (cleaner(array, stack_a, 0));
		if (check_for_int(array) > 0 && check_for_doubles(array) > 0)
		{
			if (build_stack(array, stack_a) > 0)
			{
				free_array(array);
				index++;
			}
			else
				return (cleaner(array, stack_a, 1));
		}
		else
			return (cleaner(array, stack_a, 1));
	}
	if (check_for_duplicates(stack_a) > 0)
		return (*stack_a);
	return (cleaner(array, stack_a, 0));
}
