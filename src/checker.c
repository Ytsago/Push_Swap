/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:47:15 by secros            #+#    #+#             */
/*   Updated: 2025/01/26 00:55:09 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	quit_checker(t_data *data)
{
	stack_clear(&data->lst_a);
	stack_clear(&data->lst_b);
	write(2, "Error.\n", 6);
	exit(1);
}

static void	find_rr_instr(t_data *data, char *str)
{
	if (str[1] == 'a' && str[2] == '\n')
		ft_rotate_a(data, 0);
	else if (str[1] == 'b' && str[2] == '\n')
		ft_rotate_b(data, 0);
	else if (str[1] == 'r')
	{
		if (str[2] == '\n')
			ft_rotate_r(data, 0);
		else if (str[2] == 'a' && str[3] == '\n')
			ft_rev_rotate_a(data, 0);
		else if (str[2] == 'b' && str[3] == '\n')
			ft_rev_rotate_b(data, 0);
		else if (str[2] == 'r' && str[3] == '\n')
			ft_rev_rotate_r(data, 0);
		else
			quit_checker(data);
	}
	else
		quit_checker(data);
}

static void	find_instruction(t_data *data, char *str)
{
	if (str[0] == 'p')
	{
		if (str[1] == 'a' && str[2] == '\n')
			ft_put_stacka(data, 0);
		else if (str[1] == 'b' && str[2] == '\n')
			ft_put_stackb(data, 0);
		else
			quit_checker(data);
	}
	else if (str[0] == 's')
	{
		if (str[1] == 'a' && str[2] == '\n')
			ft_swapa(data, 0);
		else if (str[1] == 'b' && str[2] == '\n')
			ft_swapb(data, 0);
		else if (str[1] == 's' && str[2] == '\n')
			ft_swaps(data, 0);
		else
			quit_checker(data);
	}
	else if (str[0] == 'r')
		find_rr_instr(data, str);
	else
		quit_checker(data);
}

static int	get_instruction(t_data *data)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		find_instruction(data, str);
		free(str);
		str = get_next_line(0);
	}
	if (check_sort(data->lst_a) && data->size_b == 0)
		return (1);
	return (0);
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
	lst_data.size_a = stack_size(lst_data.lst_a);
	lst_data.size_b = 0;
	if (ac == 1)
		return (0);
	if (get_instruction(&lst_data))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	stack_clear(&lst_data.lst_a);
	stack_clear(&lst_data.lst_b);
}
