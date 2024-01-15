/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:33:27 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:04:54 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit(1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		init_split_stack_a(&a, av);
		free_tab(av);
	}
	else
		init_stack_a(&a, av);
	if (!is_stack_sorted(a))
	{
		if (lst_len(a) == 2)
			ft_swap(&a, 1);
		else if (lst_len(a) == 3)
			sort_three_nb(&a);
		else
			sort_list(&a, &b);
	}
	free_stack(&a);
}
