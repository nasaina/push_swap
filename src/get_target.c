/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:50:50 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:54:34 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_index(t_stack *stack, int ref)
{
	int	pos;

	pos = 0;
	while (stack->next)
	{
		if (stack->nb == ref)
			break ;
		++pos;
		stack = stack->next;
	}
	return (pos);
}

int	get_target(t_stack *stack, int ref)
{
	int	pos;

	pos = check_min(stack);
	if (ref < pos)
	{
		pos = check_max(stack);
		return (pos);
	}
	while (stack)
	{
		if (stack->nb < ref && stack->nb > pos)
			pos = stack->nb;
		stack = stack->next;
	}
	return (pos);
}

int	get_target_a(t_stack *stack, int ref)
{
	int	pos;

	pos = check_max(stack);
	if (ref > check_max(stack))
	{
		pos = check_min(stack);
		return (pos);
	}
	while (stack)
	{
		if (stack->nb > ref && stack->nb < pos)
			pos = stack->nb;
		stack = stack->next;
	}
	return (pos);
}
