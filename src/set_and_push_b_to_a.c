/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_push_b_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:18 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:06:07 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//function that define the target node in a for each node now in b.
//target is always the closest biggest nb of b->nb.
//if no nb bigger, target == min nb of a.
void	set_target_b_to_a(t_stack *b, t_stack *a)
{
	t_stack	*closest_nb;
	t_stack	*tmp_a;
	t_stack	*target_node;

	while (b)
	{
		tmp_a = a;
		closest_nb = stack_max(a);
		while (tmp_a)
		{
			if (tmp_a->nb > b->nb && tmp_a->nb <= closest_nb->nb)
			{
				closest_nb = tmp_a;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (closest_nb->nb < b->nb)
			b->target_node = stack_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

//function that set all the informations needed to manipulate 
//the nodes from b to a
void	set_nodes_b_to_a(t_stack *b, t_stack *a)
{
	set_index(a);
	set_index(b);
	set_target_b_to_a(b, a);
}

//when stack b is set, rotate stack a to put the target node of b node
//on top, and then push.
void	push_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	ft_push_pa(b, a);
}

//when all nodes are finally pushed from b to a, rotate until
//the smallest value is on top. the list is now sorted.
void	put_min_on_top(t_stack **a)
{
	t_stack	*node_min;

	node_min = stack_min(*a);
	while (*a != node_min)
	{
		if (node_min->above_median)
			ft_rotate(a, 1);
		else
			ft_reverse_rotate(a, 1);
	}
}
