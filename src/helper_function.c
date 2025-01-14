/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:37:17 by secros            #+#    #+#             */
/*   Updated: 2025/01/14 18:16:18 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	lst_max(t_stack *lst)
{
	int	max;

	max = lst->content;
	while(lst)
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
	while(lst)
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
	int	x;

	lst_a = data->lst_a;
	x = lst_a->content;
	while (lst_a)
	{
		if (content > x || (content < lst_a->content && lst_a->content < x))
			x = lst_a->content;
		
		lst_a = lst_a->next;
	}
	ft_printf("\n content[%d], next[%d]\n", content, x);
	return (x);
}
/*
int	check_sort(t_list *lst)
{
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
} */