/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:07:24 by secros            #+#    #+#             */
/*   Updated: 2025/01/06 11:08:26 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_data *lst_data, t_stack **lst)
{
	int	x[3];

	x[0] = (*lst)->content;
	x[1] = (*lst)->next->content;
	x[2] = (*lst)->next->next->content;
	if (x[0] > x[1] && x[1] > x[2])
	{
		ft_swapa(lst_data, 1);
		ft_rev_rotate_a(lst_data, 1);
	}
	else if (x[0] > x[1] && x[0] > x[2])
		ft_rotate_a(lst_data, 1);
	else if (x[0] > x[1] && x[0] < x[2])
		ft_swapa(lst_data, 1);
	else if (x[0] < x[1] && x[0] > x[2])
	{
		ft_rotate_a(lst_data, 1);
		ft_rotate_a(lst_data, 1);
	}
	else
	{
		ft_rev_rotate_a(lst_data, 1);
		ft_swapa(lst_data,1);
	}
}
