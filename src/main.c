/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:28:35 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 14:54:18 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	turn_lst(t_data *data)
{
	t_stack	*lst;
	int		i;
	int		x;

	lst = data->lst_a;
	i = 0;
	x = lst_min(lst);
	while (x != lst->content)
	{
		lst = lst->next;
		i++;
	}
	while (data->lst_a->content != x)
	{
		if (i > data->size_a / 2)
			ft_rev_rotate_a(data, 1);
		else
			ft_rotate_a(data, 1);
	}
}

void	sorting(t_data *lst_data)
{
	int	i;

	i = 0;
	lst_data->size_a = stack_size(lst_data->lst_a);
	lst_data->size_b = 0;
	if (check_sort(lst_data->lst_a))
		return ;
	if (lst_data->size_a == 2)
		ft_swapa(lst_data, 1);
	else if (lst_data->size_a == 3)
		sort_three(lst_data, &lst_data->lst_a);
	else if (lst_data->size_a <= 8)
		sort_small(lst_data);
	else
		pivo_sort(lst_data);
	turn_lst(lst_data);
}

int	main(int ac, char **av)
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
	sorting(&lst_data);
}
