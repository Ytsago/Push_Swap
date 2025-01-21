/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:47:15 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 16:55:04 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	find_rr_instr(t_data *data, char *str)
{
	if (str [1] == 's')
		ft_swaps(data, 0);
	else if (str[2] == 'a')
		ft_rev_rotate_a(data, 0);
	else if (str[2] == 'b')
		ft_rev_rotate_b(data, 0);
	else if (str[2] == 'r')
		ft_rev_rotate_r(data, 0);
	else
		ft_rotate_r(data, 0);
}

static void	find_instruction(t_data *data, char *str)
{
	if (str[1] == 'a')
	{
		if (str[0] == 'p')
			ft_put_stacka(data, 0);
		else if (str[0] == 's')
			ft_swapa(data, 0);
		else if (str[0] == 'r')
			ft_rotate_a(data, 0);
	}
	else if (str[1] == 'b')
	{
		if (str[0] == 'p')
			ft_put_stackb(data, 0);
		else if (str[0] == 's')
			ft_swapb(data, 0);
		else if (str[0] == 'r')
			ft_rotate_b(data, 0);
	}
	else
		find_rr_instr(data, str);
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
	free (str);
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
	if (get_instruction(&lst_data))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	stack_clear(&lst_data.lst_a);
	stack_clear(&lst_data.lst_b);
}
