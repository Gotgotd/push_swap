/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:03 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:06:00 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//function that will rotate both stack a and b until either the cheapest node
//or either its target is on top of its stack.
void	rr_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		ft_rotate_rr(a, b);
	set_index(*a);
	set_index(*b);
}

//function that will reverse rotate both stack a and b 
//until either the cheapest node or either its target 
//is on top of its stack.
void	rrr_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		ft_reverse_rotate_rrr(a, b);
	set_index(*a);
	set_index(*b);
}

//function that finishes to rotate the stacks until both cheapest_node
//and its target are on top of their stack
void	prep_for_push(t_stack **stack, t_stack *cheapest_node, char stack_name)
{
	while (*stack != cheapest_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_node->above_median)
				ft_rotate(stack, 1);
			else
				ft_reverse_rotate(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_node->above_median)
				ft_rotate(stack, 2);
			else
				ft_reverse_rotate(stack, 2);
		}
	}
}

//Returns a pointer on the cheapest node of the stac
t_stack	*get_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//function that put the good nodes on top of their respective stacks
//and push from a to b.
void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rr_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rrr_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	ft_push_pb(a, b);
}
