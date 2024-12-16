/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:56:15 by secros            #+#    #+#             */
/*   Updated: 2024/12/15 09:27:11 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_a(t_data *lst_data, int print)
{
	t_list	*last;
	t_list	*prev;
	t_list	**lst;

	lst = &lst_data->lst_a;
	if (!*lst || !(*lst)->next)
		return ;
	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *lst;
	prev->next = NULL;
	*lst = last;
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rev_rotate_b(t_data *lst_data, int print)
{
	t_list	*last;
	t_list	*prev;
	t_list	**lst;

	lst = &lst_data->lst_b;
	if (!*lst || !(*lst)->next)
		return ;
	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *lst;
	prev->next = NULL;
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