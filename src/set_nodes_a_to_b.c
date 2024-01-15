/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:29:38 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:06:10 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//function that set the index of all nodes of a stack
void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = lst_len(stack) / 2;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		if (i < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

//function that define the target node in b for each node in a.
//target is always the closest lowest nb of a->nb.
//if no nb lower, target == max nb of b.
void	set_target_a_to_b(t_stack *a, t_stack *b)
{
	t_stack	*closest_nb;
	t_stack	*target_node;
	t_stack	*tmp_b;

	while (a)
	{
		tmp_b = b;
		closest_nb = stack_min(b);
		while (tmp_b)
		{
			if (tmp_b->nb < a->nb && tmp_b->nb >= closest_nb->nb)
			{
				closest_nb = tmp_b;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (closest_nb->nb > a->nb)
			a->target_node = stack_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

//function that count the least of moves necessary 
//for a node to be moved above its target node
void	set_push_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = lst_len(a);
	len_b = lst_len(b);
	while (a)
	{
		if (a->above_median && a->target_node->above_median)
		{
			a->push_cost = a->index;
			if (a->index < a->target_node->index)
				a->push_cost = a->target_node->index;
		}
		if (!(a->above_median) && !(a->target_node->above_median))
		{
			a->push_cost = len_a - a->index;
			if ((len_a - a->index) < (len_b - a->target_node->index))
				a->push_cost = len_b - a->target_node->index;
		}
		if (a->above_median && !a->target_node->above_median)
			a->push_cost = a->index + (len_b - a->target_node->index);
		if (!a->above_median && a->target_node->above_median)
			a->push_cost = (len_a - a->index) + a->target_node->index;
		a = a->next;
	}
}

//function that compares all the push cost and defines 
//the node whith the lesser moves necessary to go to stack "b"
void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	int		cheapest_cost;

	cheapest_node = stack;
	cheapest_cost = stack->push_cost;
	while (stack)
	{
		stack->cheapest = false;
		if (stack->push_cost < cheapest_cost)
		{
			cheapest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

//function that set all the informations needed to manipulate 
//the nodes from a to b
void	set_nodes_a_to_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a_to_b(a, b);
	set_push_cost(a, b);
	set_cheapest(a);
}
