/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:28:27 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:52 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//swap the first two nb of given stack 'a' or stack 'b'
void	ft_swap(t_stack **stack, int flag)
{
	t_stack	*tmp;

	if (!*stack || !*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
}

//swap the first two nb of both stack 'a' and stack 'b'
void	ft_swap_ss(t_stack **a, t_stack **b)
{
	ft_swap(a, 1);
	ft_swap(b, 2);
	write(1, "ss\n", 3);
}

//push the first element of stack 'b' and put it on the top of
//stack 'a'. Does nothing if 'b' is empty
void	ft_push_pa(t_stack **b, t_stack **a)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	write(1, "pa\n", 3);
}

//push the first element of stack 'a' and put it on the top of
//stack 'b'. Does nothing if 'a' is empty
void	ft_push_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	write(1, "pb\n", 3);
}
