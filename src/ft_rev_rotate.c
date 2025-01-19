/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:56:15 by secros            #+#    #+#             */
/*   Updated: 2025/01/19 15:04:02 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_a(t_data *lst_data, int print)
{
	t_stack	*last;
	t_stack	**lst;

	lst = &lst_data->lst_a;
	if (!*lst || !(*lst)->next)
		return ;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = *lst;
	last->prev->next = NULL;
	last->prev = NULL;
	(*lst)->prev = last;
	*lst = last;
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rev_rotate_b(t_data *lst_data, int print)
{
	t_stack	*last;
	t_stack	**lst;

	lst = &lst_data->lst_b;
	if (!*lst || !(*lst)->next)
		return ;
	last = stack_last(*lst);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	*lst = last;
	if (print)
		write(1, "rrb\n", 4);
}

void	ft_rev_rotate_r(t_data *lst_data)
{
	if ((!lst_data->lst_a || !lst_data->lst_a->next) 
		&& (!lst_data->lst_b || !lst_data->lst_b->next))
		return ;
	ft_rev_rotate_a(lst_data, 0);
	ft_rev_rotate_b(lst_data, 0);
	write(1, "rrr\n", 4);
}