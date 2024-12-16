/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:57:32 by secros            #+#    #+#             */
/*   Updated: 2024/12/15 17:04:46 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	find_median(t_list *lst, t_list *current, size_t size)
{
	int		x;
	size_t	count;
	t_list	*cpy;

	count = 0;
	cpy = lst;
	while (cpy)
	{
		x = *(int *)cpy->content;
		if (x < *(int *)current->content)
			count++;
		cpy = cpy->next;
	}
	if (count == size)
		return (*(int *)current->content);
	return (find_median(lst, current->next, size));
	
}

void	insert_sort(t_data *lst_data)
{
	int	x[3];

	if (!lst_data->lst_b)
		return ;
	x[0] = *(int *)lst_data->lst_a->content;
	x[1] = *(int *)lst_data->lst_b->content;
	if (lst_data->lst_b->next)
		x[2] = *(int *)lst_data->lst_b->next->content;
	if (x[0] > x[1])
	{
		ft_put_stacka(lst_data, 1);
		insert_sort(lst_data);
	}
	else if (x[0] < x[1] && x[2] < x[0])
	{
		ft_swapb(lst_data, 1);
		ft_put_stacka(lst_data, 1);
		insert_sort(lst_data);
	}
	else if (!check_sort(lst_data->lst_a) || lst_data->lst_b != NULL)
	{
		ft_rotate_a(lst_data, 1);
		insert_sort(lst_data);
	}
}

void	pivo_sort(t_data *lst_data)
{
	int		x;	
	int		med;
	size_t	len;

	len = lst_data->size_a;
	lst_data->size_a = ft_lstsize(lst_data->lst_a);
	med = find_median(lst_data->lst_a, lst_data->lst_a, lst_data->size_a / 2);
	while (lst_data->size_a > len /2 + (len % 2 != 0) && lst_data->size_a > 3)
	{
		x = *(int *)lst_data->lst_a->content;
		if (x < med)
			ft_put_stackb(lst_data, 1);
		else
			ft_rotate_a(lst_data, 1);
	}
	if (lst_data->size_a > 3)
		pivo_sort(lst_data);
	else if (!check_sort(lst_data->lst_a))
		sort_three(lst_data, &lst_data->lst_a);
	insert_sort(lst_data);
}