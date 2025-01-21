/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:00:06 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 16:58:23 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_data *data)
{
	t_stack	*a;
	t_stack	*b;

	a = data->lst_a;
	b = data->lst_b;
	while (b)
	{
		b->cheap = 0;
		b->target = just_next(data, b->content);
		b = b->next;
	}
}

static int	calc_move( int x, int y)
{
	int	cost;

	cost = 0;
	if (x * y >= 0)
	{
		if ((x > y && x > 0) || (x < y && x < 0))
			cost = absolute(x);
		else
			cost = absolute(y);
	}
	else
		cost = absolute(x) + absolute(y);
	return (cost);
}

void	*find_cheapest(t_stack *stk)
{
	t_stack	*lst;
	int		x;

	lst = stk;
	x = 1000000;
	while (lst)
	{
		lst->cost[2] = calc_move(lst->cost[0], lst->cost[1]);
		if (x > lst->cost[2])
			x = lst->cost[2];
		lst->cheap = 0;
		lst = lst->next;
	}
	while (stk)
	{
		if (stk->cost[2] == x)
		{
			stk->cheap = 1;
			return (stk);
		}
		stk = stk->next;
	}
	return (NULL);
}

void	calc_cost(t_data *data, t_stack *lst, int i)
{
	int		j;
	t_stack	*sta_a;

	j = 0;
	sta_a = data->lst_a;
	if (i > data->size_b / 2)
		i = -(data->size_b - i);
	while (sta_a)
	{
		if (sta_a->content == lst->target)
		{
			if (j > data->size_a / 2)
				j = -(data->size_a - j);
			break ;
		}
		j++;
		sta_a = sta_a->next;
	}
	lst->cost[0] = i;
	lst->cost[1] = j;
}

void	cost_rotate(t_data *data, t_stack *stk, int way, char stack)
{
	if (way == 1)
	{
		if (stack == 'R')
		{
			ft_rotate_r(data, 1);
			stk->cost[0]--;
			stk->cost[1]--;
		}
		else
		{
			if (stack == 'A')
				ft_rotate_a(data, 1);
			else if (stack == 'B')
				ft_rotate_b(data, 1);
			stk->cost[absolute('B' - stack)]--;
		}
	}
	else if (way == 0)
	{
		if (stack == 'A')
			ft_rev_rotate_a(data, 1);
		else if (stack == 'B')
			ft_rev_rotate_b(data, 1);
		stk->cost[absolute('B' - stack)]++;
	}
}
