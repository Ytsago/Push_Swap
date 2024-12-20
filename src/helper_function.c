/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:37:17 by secros            #+#    #+#             */
/*   Updated: 2024/12/20 09:13:48 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_max(t_stack *lst)
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