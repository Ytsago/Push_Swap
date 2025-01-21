/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:57:32 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 11:22:00 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "get_next_line.h"

static int	find_real_value(t_stack *lst, t_stack *cur, size_t len, size_t div)
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
	while (medium_quart(data, 2 ,3))
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
		if (data->lst_a->q  == 4)
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

int	calc_move( int x, int y)
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

//cost[0] -> lst_b cost[1] -> lst_a
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
	while(stk)
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

// void	opti_move(t_data *data, void *pt)
// {
// 	t_stack	*stk;

// 	stk = pt;
// 	while (stk->cost[0] > 0 && stk->cost[1] > 0)
// 	{
// 		ft_rotate_r(data);
// 		stk->cost[0]--;
// 		stk->cost[1]--;
// 	}
// 	while (stk->cost[0] < 0 && stk->cost[1] < 0)
// 	{
// 		ft_rev_rotate_r(data);
// 		stk->cost[0]++;
// 		stk->cost[1]++;
// 	}
// 	while (stk->cost[0] > 0)
// 	{
// 		ft_rotate_b(data, 1);
// 		stk->cost[0]--;
// 	}
// 	while (stk->cost[1] > 0)
// 	{
// 		ft_rotate_a(data, 1);
// 		stk->cost[1]--;
// 	}
// 	while (stk->cost[0] < 0)
// 	{
// 		ft_rev_rotate_b(data, 1);
// 		stk->cost[0]++;
// 	}
// 	while (stk->cost[1] < 0)
// 	{
// 		ft_rev_rotate_a(data, 1);
// 		stk->cost[1]++;
// 	}
// }

void	cost_rotate(t_data *data, t_stack *stk, int way, char stack)
{
	if (way == 1)
	{
		if (stack == 'A')
			ft_rotate_a(data, 1);
		else if (stack == 'B')
			ft_rotate_b(data, 1);
		stk->cost[absolute('B' - stack)]--;
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

void	opti_move(t_data *data, void *pt)
{
	t_stack	*stk;

	stk = pt;
	while (stk->cost[2] > 0)
	{
		if (stk->cost[0] > 0 && stk->cost[1] > 0)
		{
			ft_rotate_r(data, 1);
			stk->cost[0]--;
			stk->cost[1]--;
		}
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
	find_cheapest(data->lst_b);
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

	data->size_a = stack_size(data->lst_a);
	data->size_b = 0;
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
