/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:43:17 by secros            #+#    #+#             */
/*   Updated: 2024/12/20 08:53:46 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->cheap = 0;
	new->next = NULL;
	new->prev = NULL;
	new->content = content;
	return (new);
}

void	stack_addfront(t_stack **stack, t_stack *new)
{
	if (!stack)
		*stack = new;
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

int	stack_size(t_stack *stack)
{
	size_t	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return ((int) i);
}

void	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}