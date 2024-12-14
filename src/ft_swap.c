/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:57:12 by secros            #+#    #+#             */
/*   Updated: 2024/12/14 14:15:34 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapa(t_list **lst, int print)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (print)
		write(1, "sa", 2);
}

void	ft_swapb(t_list **lst, int print)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (print)
		write(1, "sb", 2);
}

void	ft_swaps(t_data *lst_data)
{
	ft_swapa(lst_data->lst_a, 0);
	ft_swapb(lst_data->lst_b, 0);
	if (!*(int *)lst_data->lst_a->content || !*(int *)lst_data->lst_a->next->content)
	write(1, "ss", 2);
}