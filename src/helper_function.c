/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:37:17 by secros            #+#    #+#             */
/*   Updated: 2024/12/12 15:08:05 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* int	lst_max(t_list *lst)
{
	int	max;

	max = *(int *)lst->content;
	while(lst)
	{
		if (max < *(int *)lst->content)
			max = *(int *)lst->content;
		lst = lst->next;
	}
	return (max);
}

int	lst_min(t_list *lst)
{
	int	min;

	min = *(int *)lst->content;
	while(lst)
	{
		if (min > *(int *)lst->content)
			min = *(int *)lst->content;
		lst = lst->next;
	}
	return (min);
}

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