/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:02:43 by secros            #+#    #+#             */
/*   Updated: 2024/12/14 14:06:18 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_stacka(t_list **lst_a, t_list **lst_b, int print)
{
	t_list	*tmp;

	if (!*lst_a)
		return ;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(lst_a, tmp);
	if (print)
		write(1, "pa", 2);
}

void	ft_put_stackb(t_list **lst_a, t_list **lst_b, int print)
{
	t_list	*tmp;

	if (!*lst_b)
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(lst_b, tmp);
	if (print)
		write(1, "pb", 2);
}
