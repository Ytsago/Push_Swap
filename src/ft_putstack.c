/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:02:43 by secros            #+#    #+#             */
/*   Updated: 2024/12/20 09:04:01 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_stacka(t_data *lst_data, int print)
{
	t_stack	*tmp;
	t_stack	**lst_a;
	t_stack	**lst_b;

	lst_a = &lst_data->lst_a;
	lst_b = &lst_data->lst_b;
	if (!*lst_b)
		return ;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	stack_addfront(lst_a, tmp);
	if (print)
		write(1, "pa\n", 3);
	lst_data->size_a++;
	lst_data->size_b--;
}

void	ft_put_stackb(t_data *lst_data, int print)
{
	t_stack	*tmp;
	t_stack	**lst_a;
	t_stack	**lst_b;

	lst_a = &lst_data->lst_a;
	lst_b = &lst_data->lst_b;
	if (!*lst_a)
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	stack_addfront(lst_b, tmp);
	if (print)
		write(1, "pb\n", 3);
	lst_data->size_a--;
	lst_data->size_b++;
}
