/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:45:54 by secros            #+#    #+#             */
/*   Updated: 2025/01/21 14:32:24 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dup(t_stack *lst, int x)
{
	int		y;

	while (lst)
	{
		y = lst->content;
		if (y == x)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static int	creat_stack(t_stack **lst, char *str)
{
	t_stack	*new;
	int		nb;
	long	check;

	nb = ft_atoi(str);
	check = ft_atol(str);
	if (check_dup(*lst, nb) || nb != check)
		return (0);
	new = new_stack(nb);
	if (!new)
		return (0);
	stack_addback(lst, new);
	return (1);
}

static int	only_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' ')
			i++;
		else if (ft_issign(str[i]) && (ft_isdigit(str[i + 1])
				&& (i == 0 || str[i - 1] == ' ')))
			i++;
		else
			return (0);
	}
	return (1);
}

int	parsing(t_stack **lst, char *str)
{
	char	**number;
	size_t	i;

	i = 0;
	if (!*str)
		return (0);
	if (!only_digit(str))
		return (0);
	number = ft_split(str, ' ');
	if (!number)
		return (0);
	while (number[i])
		if (!creat_stack(lst, number[i++]))
			return (free_the_mallocs(number), 0);
	return (free_the_mallocs(number), 1);
}
