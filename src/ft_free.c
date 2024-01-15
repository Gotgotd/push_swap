/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:59:21 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:37 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//function called when argument have been split.
//it means a tab have been malloced and need to be freed in case
//of error in addition with the stack.
//then display error message */
void	ft_free_split(t_stack **stack, char **av)
{
	{
		if (av)
			free_tab(av);
		if (stack)
			free_stack(stack);
		ft_error();
	}
}

//function that free the stack and display error message
void	ft_free(t_stack **stack)
{
	if (stack)
		free_stack(stack);
	ft_error();
}

//function that free the stack
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->nb = 0;
		free(*stack);
		*stack = tmp;
	}
}

//function that free the tab
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
