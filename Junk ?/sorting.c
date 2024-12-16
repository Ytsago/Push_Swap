/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:23:32 by secros            #+#    #+#             */
/*   Updated: 2024/12/10 16:55:46 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}

void	ft_put_stack(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(lst_b, tmp);
}

void	ft_rotate(t_list **lst)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	tmp->next = *lst;
	*lst = (*lst)->next;
	tmp = tmp->next;
	tmp->next = NULL;
}

void	ft_rev_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*prev;

	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *lst;
	prev->next = NULL;
	*lst = last;
}
