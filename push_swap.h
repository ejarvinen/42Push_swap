/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 07:59:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 10:06:55 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_sort
{
	int		len;
	int		bucket;
	int		ssize;
	int		bsize;
	int		nodes_pushed;
}			t_sort;

typedef struct s_opt
{
	int		max;
	int		max_index;
	int		maxx;
	int		maxx_index;
}			t_opt;

/* INPUT VALIDATION */
t_list	*input_validator(char **argv, t_list **stack_a);
int		check_for_duplicates(t_list **stack_a);
int		build_stack(char **array, t_list **stack_a);
int		substrlen(char **array);
void	set_indexes(t_list **stack_a);
int		idx_find_min(t_list *stack);

/* STACK MANIPULATION */
void	reverse_rotate(t_list **stack, int c);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	swap(t_list *stack, int c);
void	swap_both(t_list *stack_a, t_list *stack_b);
void	push(t_list **from, t_list **to, int c);
void	rotate(t_list **stack, int c);
void	rotate_both(t_list **stack_a, t_list **stack_b);

/* SORTING */
void	sort_three(t_list **stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		bucket_sort(t_list **stack_a, t_list **stack_b, int len);

/* SORT UTILS */
int		is_ascending(t_list **stack);
int		is_descending(t_list **stack);
int		find_min(t_list **stack);
int		find_max(t_list **stack);
int		find_node_location(t_list **stack, int index);
void	bring_min_ontop(t_list **stack, int c);
int		is_inlist(t_list **list, int node_index);
int		find_next_largest(t_list **stack, t_list **stash);
int		find_next_smallest(t_list **stack, t_list **stash);
void	bring_max_ontop(t_list **stack, int c);
void	get_max_three(t_list **stack, t_list **power_three);
int		get_two_largest(t_list **stack, t_list **power_couple);
int		get_two_smallest(t_list **stack, t_list **double_trouble);
void	bring_maxtwo_ontop(t_list **stack, t_list **power_couple, int c);
t_list	*find_node(t_list **lst, int index);
int		push_last_two(t_list **stack_a, t_list **stack_b);
void	arrange_stack(t_list **stack, int c);
int		determine_factor(int ra, int rra, t_list **stack_a);
void	update_bucket(t_list **stack_b, t_sort *sort_specs);
void	rotate_stack(t_list **stack_a, int *factor);
int		rotate_stacka(t_list **stack_a, t_list **double_trouble);
int		rafactor(t_list **stack_a, t_list **double_trouble);
int		rrafactor(t_list **stack_a, t_list **double_trouble, int *ra);
void	push_to_b(t_list **stack_a, t_list **stack_b, t_sort *sort_specs);
void	empty_stack_a_big(t_list **stack_a, t_list **stack_b,
			t_list **secret_stack, t_sort *sort_specs);
void	empty_stack_a_small(t_list **stack_a, t_list **stack_b,
			t_list **secret_stack, t_sort *sort_specs);

/* CLEANUP */
void	free_array(char **array);
void	free_list(t_list **lst);
t_list	*cleaner(char **array, t_list **lst, int green_light);

int		main(int argc, char **argv);

#endif