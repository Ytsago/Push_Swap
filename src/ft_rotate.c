/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:47:40 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 14:35:36 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_data *lst_data, int print)
{
	t_stack	*tmp;
	t_stack	**lst;

	lst = &lst_data->lst_a;
	if (!*lst || !(*lst)->next)
		return ;
	tmp = stack_last(*lst);
	tmp->next = *lst;
	(*lst)->prev = tmp;
	*lst = (*lst)->next;
	tmp = tmp->next;
	tmp->next = NULL;
	(*lst)->prev = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_data *lst_data, int print)
{
	t_stack	*tmp;
	t_stack	**lst;

	lst = &lst_data->lst_b;
	if (!*lst || !(*lst)->next)
		return ;
	tmp = stack_last(*lst);
	tmp->next = *lst;
	(*lst)->prev = tmp;
	*lst = (*lst)->next;
	tmp = tmp->next;
	tmp->next = NULL;
	(*lst)->prev = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rotate_r(t_data *lst_data, int print)
{
	if ((!lst_data->lst_a || !lst_data->lst_a->next)
		&& (!lst_data->lst_b || !lst_data->lst_b->next))
		return ;
	ft_rotate_a(lst_data, 0);
	ft_rotate_b(lst_data, 0);
	if (print)
		write(1, "rr\n", 3);
}
