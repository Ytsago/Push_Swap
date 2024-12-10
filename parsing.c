/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:45:54 by secros            #+#    #+#             */
/*   Updated: 2024/12/10 16:56:35 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	check_dup(t_list **lst, int x)
{
	t_list	*tmp;
	int		y;

	tmp = *lst;
	while (tmp)
	{
		y = *(int *)tmp->content;
		if (y == x)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	creat_stack(t_list **lst, char *str)
{
	t_list	*new;
	int		*nb;

	nb = malloc(sizeof(int));
	if (!nb)
		return (0);
	*nb = ft_atoi(str);
	if (check_dup(lst, *nb))
		return (free(nb), 0);
	new = ft_lstnew(nb);
	if (!new)
		return (free(nb), 0);
	ft_lstadd_back(lst, new);
	return (1);
}

static int	only_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == ' ') && (str[i] == '-'
				&& (i > 0 && str[i - 1] != ' ' || !ft_isdigit(str[i + 1]))))
			return (0);
		i++;
	}
	return (1);
}

int	parsing(t_list **lst, char *str)
{
	int		*nb;
	char	**number;
	size_t	i;

	i = 0;
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
/*
int	main()
{
	t_list *lst;
	t_list	*lst2;
	t_list	*tmp;
	lst = NULL;
	lst2 = NULL;
	char *str = "1 2 3 4 5 6 7 8 9";
	//printf("%d\n", parsing(&lst, str));
	parsing(&lst, str);
	ft_rev_rotate(&lst);
	tmp = lst;
	while (lst)
	{
		printf("lst 1 :%d\n", *(int*)lst->content);
		lst = lst->next;
	}
	while (lst2)
	{
		printf("lst 2 :%d\n", *(int*)lst2->content);
		lst2 = lst2->next;
	}
	ft_lstclear(&tmp, free);
} */