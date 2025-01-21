/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:00:54 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 16:12:39 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	find_real_value(t_stack *lst, t_stack *cur, size_t len, size_t div)
{
	int		x;
	size_t	count;
	t_stack	*cpy;

	count = 0;
	cpy = lst;
	while (cpy)
	{
		x = cpy->content;
		if (x < cur->content)
			count++;
		cpy = cpy->next;
	}
	if (count == len / div)
		return (cur->content);
	return (find_real_value(lst, cur->next, len, div));
}

int	find_quart(t_data *data, int x)
{
	if (x <= data->q[0])
		return (1);
	if (x <= data->med)
		return (2);
	if (x <= data->q[1])
		return (3);
	if (x > data->q[1])
		return (4);
	else
	{
		ft_printf("Error when proccessing the value %d", x);
		return (-1);
	}
}

int	medium_quart(t_data *data, int x, int y)
{
	t_stack	*lst;

	lst = data->lst_a;
	while (lst)
	{
		if (lst->q == x || lst->q == y)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	quart_push(t_data *data)
{
	while (medium_quart(data, 2, 3))
	{
		if (data->lst_a->q == 3)
			ft_put_stackb(data, 1);
		else if (data->lst_a->q == 2)
		{
			ft_put_stackb(data, 1);
			ft_rotate_b(data, 1);
		}
		else
			ft_rotate_a(data, 1);
	}
	while (data->size_a > 3)
	{
		if (data->lst_a->q == 4)
			ft_put_stackb(data, 1);
		else
		{
			ft_put_stackb(data, 1);
			ft_rotate_b(data, 1);
		}
	}
}

void	set_quart(t_data *data, t_stack *lst)
{
	while (lst)
	{
		lst->q = find_quart(data, lst->content);
		lst = lst->next;
	}
}
