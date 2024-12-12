/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:47:51 by secros            #+#    #+#             */
/*   Updated: 2024/12/11 18:25:06 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "helper_function.h"

static void	sort_algo(t_list **lst_a, t_list **lst_b);

void	sort_init(t_list **lst_a, t_list **lst_b)
{
	ft_put_stack(lst_a, lst_b);
	ft_put_stack(lst_a, lst_b);
	write(1,"pb\npb\n", 6);
	sort_algo(lst_a, lst_b);
}

static int	insert(t_list **lst_a, t_list **lst_b)
{
	int	current;
	int	min;

	min = lst_min(*lst_b);
	current = *(int *)(*lst_a)->content;
	if (current > lst_max(*lst_b) || current < min)
	{
		ft_put_stack(lst_a, lst_b);
		write(1, "pb\n", 3);
		if (current < min)
		{
			ft_rotate(lst_b);
			write (1, "rb\n", 3);
		}
		return (1);
	}
	return (0);
}

static int	numb_rot(t_list *lst_a, t_list *lst_b)
{
	int		current;
	size_t	next;
	size_t	size;

	size = ft_lstsize(lst_b);
	current = *(int *)lst_a->content;
	next = just_next(lst_b, current);
	printf("current : %d, size : %d, next : %d\n",current,  size, next);
	if (next > size / 2)
		next = -(size - next);
	return (next);
}

static void	sort_algo(t_list **lst_a, t_list **lst_b)
{
	printf("sorting\n");
	if (check_sort(*lst_a))
		return ;
	if (insert(lst_a, lst_b))
		return (sort_algo(lst_a, lst_b));
	printf("%d", numb_rot(*lst_a, *lst_b));
}
