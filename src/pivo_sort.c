/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:57:32 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 16:19:38 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_move(t_data *data, void *pt)
{
	t_stack	*stk;

	stk = pt;
	while (stk->cost[2] > 0)
	{
		if (stk->cost[0] > 0 && stk->cost[1] > 0)
			cost_rotate(data, stk, 1, 'R');
		if (stk->cost[0] < 0 && stk->cost[1] < 0)
		{
			ft_rev_rotate_r(data, 1);
			stk->cost[0]++;
			stk->cost[1]++;
		}
		if (stk->cost[0] > 0)
			cost_rotate(data, stk, 1, 'B');
		if (stk->cost[1] > 0)
			cost_rotate(data, stk, 1, 'A');
		if (stk->cost[0] < 0)
			cost_rotate(data, stk, 0, 'B');
		if (stk->cost[1] < 0)
			cost_rotate(data, stk, 0, 'A');
		stk->cost[2]--;
	}
}

void	opti_sort(t_data *data)
{
	t_stack			*lst;
	int				i;

	i = 0;
	lst = data->lst_b;
	while (lst)
	{
		calc_cost(data, lst, i);
		lst = lst->next;
		i++;
	}
	opti_move(data, find_cheapest(data->lst_b));
	ft_put_stacka(data, 1);
	incert_sort(data);
}

void	incert_sort(t_data *data)
{
	t_stack	*lst[2];

	if (data->size_b == 0)
		return ;
	lst[0] = data->lst_a;
	lst[1] = data->lst_b;
	set_target(data);
	opti_sort(data);
}

void	pivo_sort(t_data *data)
{
	size_t	len;

	len = data->size_a;
	data->med = find_real_value(data->lst_a, data->lst_a, len, 2);
	data->q[0] = find_real_value(data->lst_a, data->lst_a, len, 4);
	data->q[1] = find_real_value(data->lst_a, data->lst_a, len * 3, 4);
	set_quart(data, data->lst_a);
	quart_push(data);
	if (!check_sort(data->lst_a))
		sort_three(data, &data->lst_a);
	incert_sort(data);
}
