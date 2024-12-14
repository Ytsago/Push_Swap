/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:07:24 by secros            #+#    #+#             */
/*   Updated: 2024/12/14 12:56:46 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *lst)
{
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_three(t_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*lst)->content;
	b = *(int *)(*lst)->next->content;
	c = *(int *)(*lst)->next->next->content;
	if (check_sort(*lst))
		return ;
	if (a > b && b > c)
	{
		
	}
}
