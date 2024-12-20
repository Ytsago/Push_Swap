/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:57:12 by secros            #+#    #+#             */
/*   Updated: 2024/12/20 09:12:42 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapa(t_data *lst_data, int print)
{
	t_stack	*tmp;
	t_stack	**lst;

	lst = &lst_data->lst_a;
	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	tmp->prev = (*lst);
	(*lst)->next = tmp;
	(*lst)->prev = NULL;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_swapb(t_data *lst_data, int print)
{
	t_stack	*tmp;
	t_stack	**lst;

	lst = &lst_data->lst_b;
	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	tmp->prev = (*lst);
	(*lst)->next = tmp;
	(*lst)->prev = NULL;
	if (print)
		write(1, "sb\n", 3);
}

void	ft_swaps(t_data *lst_data)
{
	t_stack	**lst_a;
	t_stack	**lst_b;

	lst_a = &lst_data->lst_a;
	lst_b = &lst_data->lst_b;
	if (!*lst_a || !*lst_b)
		return ;
	if (!(*lst_a)->next || !(*lst_b)->next)
		return ;
	ft_swapa(lst_data, 0);
	ft_swapb(lst_data, 0);
	write(1, "ss\n", 3);
}
