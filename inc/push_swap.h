/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:19 by secros            #+#    #+#             */
/*   Updated: 2024/12/20 08:58:06 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				content;
	int				cost;
	int				cheap;
	int				target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	t_stack		*lst_a;
	t_stack		*lst_b;
	size_t		size_a;
	size_t		size_b;
}				t_data;

int		parsing(t_stack **lst, char *str);

//Instruction function :
void	ft_swapa(t_data *lst_data, int print);
void	ft_swapb(t_data *lst_data, int print);
void	ft_swaps(t_data *lst_data);

void	ft_put_stacka(t_data *lst_data, int print);
void	ft_put_stackb(t_data *lst_data, int print);

void	ft_rotate_a(t_data *lst_data, int print);
void	ft_rotate_b(t_data *lst_data, int print);
void	ft_rotate_r(t_data *lst_data);

void	ft_rev_rotate_a(t_data *lst_data, int print);
void	ft_rev_rotate_b(t_data *lst_data, int print);
void	ft_rev_rotate_r(t_data *lst_data);

//stack functiom
void	*new_stack(int content);
void	stack_addfront(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
void	*stack_last(t_stack *stack);

//utils
int	check_sort(t_stack *lst);
int	lst_max(t_stack *lst);
int	lst_min(t_stack *lst);

//sort three
void	sort_three(t_data *lst_data, t_list **lst);

//pivo sort
void	pivo_init(t_data *lst_data);
void	pivo_sort(t_data *lst_data);

#endif