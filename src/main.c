/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:28:35 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 10:45:24 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "get_next_line.h"

void	debugg(t_data *data)
{
	t_stack	*lsta[2];
	
	lsta[0] = data->lst_a;
	lsta[1] = data->lst_b;
	ft_printf("--------------------------------\nlst a :\n");
	while (lsta[0])
	{
		if (lsta[0]->prev == NULL)
			ft_printf("nill<--  ");
		else
			ft_printf("%d<--  ", lsta[0]->prev->content);
		ft_printf("%d  -->  ", lsta[0]->content);
		if (lsta[0]->next == NULL)
			ft_printf("nill");
		else
			ft_printf("%d\n", lsta[0]->next->content);
		//ft_printf("q[%d] target[%d]\n", lsta[0]->content, lsta[0]->q, lsta[0]->target);
		lsta[0] = lsta[0]->next;
	}
	ft_printf("\n\nlst b :\n");
	while (lsta[1])
	{
		if (lsta[1]->prev == NULL)
			ft_printf("nill");
		else
			ft_printf("%d", lsta[1]->prev->content);
		ft_printf("  <---  %d  --->  ", lsta[1]->content);
		if (lsta[1]->next == NULL)
			ft_printf("nill");
		else
			ft_printf("%d\n", lsta[1]->next->content);
		//ft_printf("cost[%d][%d] target[%d] cost_t[%d], cheap[%d]\n", lsta[1]->content, lsta[1]->cost[0], lsta[1]->cost[1], lsta[1]->target, lsta[1]->cost[2], lsta[1]->cheap);
		lsta[1] = lsta[1]->next;
	}
	get_next_line(0);
}

void	sorting(t_data *lst_data)
{
	t_stack *lst;
	int		i;

	i = 0;
	if(check_sort(lst_data->lst_a))
		return ;
	if (lst_data->size_a == 2)
		ft_swapa(lst_data, 1);
	else if (lst_data->size_a == 3)
		sort_three(lst_data, &lst_data->lst_a);
	else
		pivo_sort(lst_data);
	lst = lst_data->lst_a;
	while (lst->content != lst_min(lst_data->lst_a))
	{
		lst = lst->next;
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
	//debugg(&lst_data);
}
