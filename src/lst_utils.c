/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:58:37 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:48 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//creating new node for nb
t_stack	*lstnew(long *content)
{
	t_stack	*tab;

	tab = malloc(sizeof(t_stack));
	if (!tab)
		return (NULL);
	tab->nb = *content;
	tab->next = NULL;
	return (tab);
}

//adding the node at the end of the list
void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

//calculate length of the stack
int	lst_len(t_stack *lst)
{
	int	len;

	len = 0;
	if (!lst)
		return (len);
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

//function that returns the lowest number in given stack
t_stack	*stack_min(t_stack *stack)
{
	t_stack	*min_node;

	min_node = stack;
	while (stack->next)
	{
		if (stack->next->nb < min_node->nb)
			min_node = stack->next;
		stack = stack->next;
	}
	return (min_node);
}

//function that returns the biggest number in given stack
t_stack	*stack_max(t_stack *stack)
{
	t_stack	*max_node;

	max_node = stack;
	while (stack->next)
	{
		if (stack->next->nb > max_node->nb)
			max_node = stack->next;
		stack = stack->next;
	}
	return (max_node);
}
