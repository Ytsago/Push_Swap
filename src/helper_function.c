/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:37:17 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 16:26:56 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	lst_max(t_stack *lst)
{
	int	max;

	max = lst->content;
	while (lst)
	{
		if (max < lst->content)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

int	lst_min(t_stack *lst)
{
	int	min;

	min = lst->content;
	while (lst)
	{
		if (min > lst->content)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

int	just_next(t_data *data, int content)
{
	t_stack	*lst_a;
	int		x;

	lst_a = data->lst_a;
	x = lst_a->content;
	if (content > lst_max(lst_a) || content < lst_min(lst_a))
		return (lst_min(lst_a));
	while (lst_a)
	{
		if (content > x || (content < lst_a->content && lst_a->content < x))
			x = lst_a->content;
		lst_a = lst_a->next;
	}
	return (x);
}

int	absolute(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

int	check_sort(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
