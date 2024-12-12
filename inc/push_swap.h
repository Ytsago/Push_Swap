/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:19 by secros            #+#    #+#             */
/*   Updated: 2024/12/11 19:03:06 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void	ft_swap(t_list **lst);
void	*ft_put_stack(t_list **lst_a, t_list **lst_b);
void	ft_rotate(t_list **lst);
void	ft_rev_rotate(t_list **lst);

int		lst_min(t_list *lst);
int		lst_max(t_list *lst);
int		check_sort(t_list *lst);

int		parsing(t_list **lst, char *str);

#endif