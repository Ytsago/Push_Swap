/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:19 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 16:12:23 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				content;
	int				q;
	int				cost[3];
	int				cheap;
	int				target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	t_stack		*lst_a;
	t_stack		*lst_b;
	int			med;
	int			q[2];
	int			size_a;
	int			size_b;
}				t_data;

int		parsing(t_stack **lst, char *str);

//Instruction function :
void	ft_swapa(t_data *lst_data, int print);
void	ft_swapb(t_data *lst_data, int print);
void	ft_swaps(t_data *lst_data, int print);

void	ft_put_stacka(t_data *lst_data, int print);
void	ft_put_stackb(t_data *lst_data, int print);

void	ft_rotate_a(t_data *lst_data, int print);
void	ft_rotate_b(t_data *lst_data, int print);
void	ft_rotate_r(t_data *lst_data, int print);

void	ft_rev_rotate_a(t_data *lst_data, int print);
void	ft_rev_rotate_b(t_data *lst_data, int print);
void	ft_rev_rotate_r(t_data *lst_data, int print);

//stack functiom
void	*new_stack(int content);
void	stack_addfront(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
void	stack_addback(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);

//utils
int		check_sort(t_stack *lst);
int		lst_max(t_stack *lst);
int		lst_min(t_stack *lst);
int		just_next(t_data *data, int content);
int		absolute(int x);

//sort three
void	sort_three(t_data *lst_data, t_stack **lst);
void	sort_small(t_data *data);

//pivo sort
void	incert_sort(t_data *data);
void	pivo_init(t_data *lst_data);
void	pivo_sort(t_data *lst_data);

//incertion sort
void	*find_cheapest(t_stack *stk);
void	calc_cost(t_data *data, t_stack *lst, int i);
void	cost_rotate(t_data *data, t_stack *stk, int way, char stack);
void	set_target(t_data *data);
int		find_real_value(t_stack *lst, t_stack *cur, size_t len, size_t div);
void	set_quart(t_data *data, t_stack *lst);
void	quart_push(t_data *data);

#endif