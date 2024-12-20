/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:28:35 by secros            #+#    #+#             */
/*   Updated: 2024/12/20 09:14:08 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	sorting(t_data *lst_data)
{
	if(check_sort(lst_data->lst_a))
		return ;
	if (lst_data->size_a == 2)
		ft_swapa(lst_data, 1);
	if (lst_data->size_a == 3)
		sort_three(lst_data, &lst_data->lst_a);
	pivo_sort(lst_data);
	while (*(int *)lst_data->lst_a->content != lst_min(lst_data->lst_a))
		ft_rev_rotate_a(lst_data, 1);
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
			return (ft_lstclear(&lst_data.lst_a, free), 1);
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
		ft_printf("%d\n", *(int *)lst_data.lst_a->content);
		lst_data.lst_a = lst_data.lst_a->next;
	}
	ft_printf("\nlst b :\n");
	while (lst_data.lst_b)
	{
		ft_printf("%d\n", *(int *)lst_data.lst_b->content);
		lst_data.lst_b = lst_data.lst_b->next;
	}
}
