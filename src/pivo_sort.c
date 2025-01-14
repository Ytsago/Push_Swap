/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:57:32 by secros            #+#    #+#             */
/*   Updated: 2025/01/14 19:09:16 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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
	int	rot;

	rot = 0;
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
		b->target = just_next(data, b->content);
		b = b->next;
	}
}

void	find_cheapest(t_stack **stk)
{
	t_stack	*lst;
	int		x;

	lst = *stk;
	x = lst->cost;
	while (lst)
	{
		if (lst->cost < x)
			x = lst->cost;
		lst = lst->next;
	}
	lst = *stk;
	while (lst)
	{
		if (lst->cost == x)
		{
			lst->cheap = 1;
			return ;
		}
		lst = lst->next;
	}
}

void	calc_cost(t_data *data, t_stack **lst, int i)
{
	int		j;
	t_stack	*sta_a;

	j = 0;
	sta_a = data->lst_a;
	if (i > data->size_b / 2)
		i = -(data->size_b - i);
	while (sta_a)
	{
		ft_printf("\ncontent[%d], target[%d], j[%d]", sta_a->content, (*lst)->target, j);
		if (sta_a->content == (*lst)->target)
		{
			if (j > data->size_a / 2)
				j = -(data->size_a - j);
			break ;
		}
		j++;
		sta_a = sta_a->next;
	}
	(*lst)->cost = i + j;
}

void	opti_sort(t_data *data)
{
	t_stack			*lst;
	int				i;

	i = 0;
	lst = data->lst_b;
	while (lst)
	{
		calc_cost(data, &lst, i);
		lst = lst->next;
		i++;
	}
	find_cheapest(&data->lst_b);
}

void	incert_sort(t_data *data)
{
	t_stack	*lst[2];

	lst[0] = data->lst_a;
	lst[1] = data->lst_b;
	set_target(data);
	if (lst[1]->content > lst_max(lst[0]) && lst[0]->content == lst_min(lst[0]))
	{
		ft_put_stacka(data, 1);
		return (ft_rotate_a(data, 1), incert_sort(data));
	}
	if (lst[1]->content < lst_min(lst[0]) && lst[0]->content == lst_min(lst[0]))
		return (ft_put_stacka(data, 1), incert_sort(data));
	if (lst[1]->target == lst[0]->content)
		return (ft_put_stacka(data, 1), incert_sort(data));
	if (stack_last(data->lst_a)->content == lst[1]->target)
	{
		ft_rev_rotate_a(data, 1);
		return (ft_put_stacka(data, 1), incert_sort(data));
	}
	else
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
	ft_printf("q1[%d], med[%d], q2[%d], size_a[%d]\n", data->q[0], data->med, data->q[1], data->size_a);
	set_quart(data, data->lst_a);
	quart_push(data);
	if (!check_sort(data->lst_a))
		sort_three(data, &data->lst_a);
	incert_sort(data);
}
