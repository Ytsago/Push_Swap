/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:19 by secros            #+#    #+#             */
/*   Updated: 2024/12/10 16:47:35 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "libft.h"

void	ft_swap(t_list **lst);
void	*ft_put_stack(t_list **lst_a, t_list **lst_b);
void	ft_rotate(t_list **lst);
void	ft_rev_rotate(t_list **lst);

#endif