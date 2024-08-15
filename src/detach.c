/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:45:41 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 10:53:41 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*detach_first(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if ((*stack)->next)
		*stack = (*stack)->next;
	current->next = NULL;
	return (current);
}

t_stack	*detach_last(t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*prev;

	cursor = *stack;
	while (cursor->next)
	{
		prev = cursor;
		cursor = cursor->next;
	}
	prev->next = NULL;
	return (cursor);
}
