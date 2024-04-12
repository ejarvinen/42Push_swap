/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:21:25 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 08:32:07 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
frees nodes in a linked list when node content isn't malloced
*/
void	free_list(t_list **lst)
{
	t_list	*node;

	node = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(node);
		node = *lst;
	}
	*lst = NULL;
}

/*
frees a 2D array
*/
void	free_array(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

/*
performs ft_lstclear and returns a NULL node
*/
t_list	*cleaner(char **array, t_list **lst, int green_light)
{
	if (green_light)
		free_array(array);
	if (*lst)
		ft_lstclear(lst, free);
	return (NULL);
}
