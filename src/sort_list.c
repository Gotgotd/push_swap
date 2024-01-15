/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:26:42 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:06:14 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//check if stack a is sorted in ascending order
int	is_stack_sorted(t_stack *a)
{
	int	i;

	if (!a)
		ft_error();
	i = a->nb;
	while (a)
	{
		if (i > a->nb)
			return (0);
		i = a->nb;
		a = a->next;
	}
	return (1);
}

//function that sort the numbers in ascending order in stack a
void	sort_list(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = lst_len(*a);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		ft_push_pb(a, b);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		ft_push_pb(a, b);
	while (len_a-- > 3 && !is_stack_sorted(*a))
	{
		set_nodes_a_to_b(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three_nb(a);
	while (*b)
	{
		set_nodes_b_to_a(*b, *a);
		push_b_to_a(a, b);
	}
	set_index(*a);
	put_min_on_top(a);
}
