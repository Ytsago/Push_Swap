/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:28:35 by secros            #+#    #+#             */
/*   Updated: 2024/12/11 19:29:31 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	main (int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;

	lst_a = NULL;
	lst_b = NULL;
	i = 1;
	while (i < ac)
	{
		if (!parsing(&lst_a, av[i++]))
		{
			write(2, "Error\n", 6);
			return (ft_lstclear(&lst_a, free), 1);
		}
	}
	if (!lst_a)
		return (0);
}