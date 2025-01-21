/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:07:24 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 14:35:10 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_data *data)
{
	while (data->size_a > 3)
		ft_put_stackb(data, 1);
	if (!check_sort(data->lst_a))
		sort_three(data, &data->lst_a);
	while (data->size_b > 0)
		incert_sort(data);
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
		ft_swapa(lst_data, 1);
	}
}
