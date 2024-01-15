/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:54:04 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:25 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//print error and exit program
void	ft_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

//function that check if there is duplicates in stack a
int	check_duplicate(t_stack *lst, int j)
{
	while (lst)
	{
		if (lst->nb == j)
			return (1);
		lst = lst->next;
	}
	return (0);
}

//check if there is only digits in the argument.
//if not, return 1 to free and display error messsage.
//return 0 if all is ok.
int	check_digit(char *av)
{
	int	j;

	j = 0;
	if (!av[j])
		return (1);
	if (av[j] == '-')
		j++;
	if (av[j] == '+')
		j++;
	while (av[j])
	{
		if (av[j] < '0' || av[j] > '9')
			return (1);
		j++;
	}
	return (0);
}
