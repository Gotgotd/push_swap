/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:03:36 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:06:18 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//sort the list when there is only 3 numbers in it
void	sort_three_nb(t_stack **stack)
{
	t_stack	*max_node;

	max_node = stack_max(*stack);
	if (max_node == *stack)
		ft_rotate(stack, 1);
	else if ((*stack)->next == max_node)
		ft_reverse_rotate(stack, 1);
	if ((*stack)->nb > (*stack)->next->nb)
		ft_swap(stack, 1);
}
