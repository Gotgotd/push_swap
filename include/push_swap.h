/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:25 by gdaignea          #+#    #+#             */
/*   Updated: 2024/01/15 12:06:57 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	int				push_cost;
	bool			cheapest;
	bool			above_median;
	struct s_stack	*next;
	struct s_stack	*target_node;
}	t_stack;

/* INIT STACK A */
void	init_stack_a(t_stack **a, char **av);
void	init_split_stack_a(t_stack **a, char **av);
long	atoi_arg(const char *str);

/* SORT THREE NB*/
void	sort_three_nb(t_stack **stack);

/* SORT LIST */
int		is_stack_sorted(t_stack *a);
void	sort_list(t_stack **a, t_stack **b);

/* SET NODES A TO B*/
void	set_nodes_a_to_b(t_stack *a, t_stack *b);
void	set_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	set_target_a_to_b(t_stack *a, t_stack *b);
void	set_push_cost(t_stack *a, t_stack *b);

/* PUSH A to B */
void	rr_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rrr_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	prep_for_push(t_stack **stack, t_stack *cheapest_node, char stack_name);
t_stack	*get_cheapest_node(t_stack *stack);
void	push_a_to_b(t_stack **a, t_stack **b);

/* SET AND PUSH B TO A */
void	set_target_b_to_a(t_stack *b, t_stack *a);
void	set_nodes_b_to_a(t_stack *b, t_stack *a);
void	push_b_to_a(t_stack **a, t_stack **b);
void	put_min_on_top(t_stack **a);

/* LST UTILS FUNCTIONS */
t_stack	*lstnew(long *content);
void	lstadd_back(t_stack **lst, t_stack *new);
t_stack	*stack_min(t_stack *stack);
t_stack	*stack_max(t_stack *stack);
int		lst_len(t_stack *lst);

/* OPERATIONS 1 */
void	ft_swap(t_stack **stack, int flag);
void	ft_swap_ss(t_stack **a, t_stack **b);
void	ft_push_pa(t_stack **b, t_stack **a);
void	ft_push_pb(t_stack **a, t_stack **b);

/* OPERATIONS 2 */
void	ft_rotate(t_stack **stack, int flag);
void	ft_rotate_rr(t_stack **a, t_stack **b);
void	ft_reverse_rotate(t_stack **stack, int flag);
void	ft_reverse_rotate_rrr(t_stack **a, t_stack **b);

/* ERROR */
void	ft_error(void);
int		check_duplicate(t_stack *lst, int j);
int		check_digit(char *av);

/* FREE */
void	ft_free(t_stack **stack);
void	ft_free_split(t_stack **stack, char **av);
void	free_tab(char **tab);
void	free_stack(t_stack **stack);

#endif