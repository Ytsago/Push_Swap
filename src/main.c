/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:28:35 by secros            #+#    #+#             */
/*   Updated: 2025/01/19 15:12:18 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	sorting(t_data *lst_data)
{
	t_stack *lst;
	int		i;

	i = 0;
	if(check_sort(lst_data->lst_a))
		return ;
	if (lst_data->size_a == 2)
		ft_swapa(lst_data, 1);
	if (lst_data->size_a == 3)
		sort_three(lst_data, &lst_data->lst_a);
	pivo_sort(lst_data);
	lst = lst_data->lst_a;
	while (lst->content != lst_min(lst_data->lst_a))
	{
		lst =lst->next;
		i++;
	}
	while (i > lst_data->size_a / 2 && i < lst_data->size_a)
	{
		ft_rev_rotate_a(lst_data, 1);
		i++;
	}
	while(i < lst_data->size_a / 2 && i != 0)
	{
		ft_rotate_a(lst_data, 1);
		i--;
	}
}
int	main (int ac, char **av)
{
	t_data	lst_data;
	int		i;

	lst_data.lst_a = NULL;
	lst_data.lst_b = NULL;
	i = 1;
	while (i < ac)
	{
		if (!parsing(&lst_data.lst_a, av[i++]))
		{
			write(2, "Error\n", 6);
			return (stack_clear(&lst_data.lst_a), 1);
		}
	}
	if (!lst_data.lst_a)
		return (0);
	lst_data.size_a = stack_size(lst_data.lst_a);
	lst_data.size_b = 0;
	sorting(&lst_data);
 	ft_printf("\nlst a :\n");
	while (lst_data.lst_a)
	{
		ft_printf("%d q[%d] target[%d]\n", lst_data.lst_a->content, lst_data.lst_a->q, lst_data.lst_a->target);
		lst_data.lst_a = lst_data.lst_a->next;
	}
	ft_printf("\nlst b :\n");
	while (lst_data.lst_b)
	{
		ft_printf("%d cost[%d][%d] target[%d] cost_t[%d], cheap[%d]\n", lst_data.lst_b->content, lst_data.lst_b->cost[0], lst_data.lst_b->cost[1], lst_data.lst_b->target, lst_data.lst_b->cost[2], lst_data.lst_b->cheap);
		lst_data.lst_b = lst_data.lst_b->next;
	}
}
