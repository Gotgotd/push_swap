/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:04:49 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:56 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//shift up all elements of a stack. 
//The first one becomes the last.
void	ft_rotate(t_stack **stack, int flag)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
	else if (flag == 2)
		write(1, "rb\n", 3);
}

//rotate both stacks at the same time 
void	ft_rotate_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	write(1, "rr\n", 3);
}

//shift down all elements of a stack
//last one becomes the first
void	ft_reverse_rotate(t_stack **stack, int flag)
{
	t_stack	*tmp;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		before_last = tmp;
		tmp = tmp->next;
	}
	tmp->next = *stack;
	*stack = tmp;
	before_last->next = NULL;
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 2)
		write(1, "rrb\n", 4);
}

//reverse rotate both stacks at the same time
void	ft_reverse_rotate_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, 0);
	ft_reverse_rotate(b, 0);
	write(1, "rrr\n", 4);
}
