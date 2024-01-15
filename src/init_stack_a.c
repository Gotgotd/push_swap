/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:41:59 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:44 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//transform argument from char to int
long	atoi_arg(const char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

//takes arguments and if valids, put them in stack a
void	init_stack_a(t_stack **a, char **av)
{
	int		i;
	long	j;

	i = 1;
	while (av[i])
	{
		if (check_digit(av[i]) == 1)
			ft_free(a);
		j = atoi_arg(av[i]);
		if (j < INT_MIN || j > INT_MAX)
			ft_free(a);
		if (check_duplicate(*a, j) == 1)
			ft_free(a);
		lstadd_back(a, lstnew(&j));
		i++;
	}
}

//take arguments that were just splitted
void	init_split_stack_a(t_stack **a, char **av)
{
	int		i;
	long	j;

	i = 0;
	if (!av[0])
	{
		ft_free_split(a, av);
		ft_error();
	}
	while (av[i])
	{
		if (check_digit(av[i]))
			ft_free_split(a, av);
		j = atoi_arg(av[i]);
		if (j < INT_MIN || j > INT_MAX)
			ft_free_split(a, av);
		if (check_duplicate(*a, j) == 1)
			ft_free_split(a, av);
		lstadd_back(a, lstnew(&j));
		i++;
	}
}
