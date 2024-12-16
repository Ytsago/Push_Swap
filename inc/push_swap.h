/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:19 by secros            #+#    #+#             */
/*   Updated: 2024/12/15 14:56:56 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_data
{
	t_list		*lst_a;
	t_list		*lst_b;
	size_t		size_a;
	size_t		size_b;
}				t_data;

int		parsing(t_list **lst, char *str);

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

//utils
int	check_sort(t_list *lst);
int	lst_max(t_list *lst);
int	lst_min(t_list *lst);

//sort three
void	sort_three(t_data *lst_data, t_list **lst);

//pivo sort
void	pivo_init(t_data *lst_data);
void	pivo_sort(t_data *lst_data);

#endif