/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:42:12 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:53:19 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_max(t_stack *stack)
{
	int	max;

	max = stack->nb;
	while (stack)
	{
		if (max < stack->nb)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

int	check_min(t_stack *stack)
{
	int	min;

	min = stack->nb;
	while (stack)
	{
		if (min >= stack->nb)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

int	check_pos_min(t_stack *stack)
{
	int	min;
	int	pos;

	pos = 0;
	min = stack->nb;
	while (stack)
	{
		++pos;
		min = stack->nb;
		if (min == check_min(stack))
			break ;
		stack = stack->next;
	}
	return (pos);
}

int	check_pos_max(t_stack *stack)
{
	int	max;
	int	pos;

	pos = 0;
	max = stack->nb;
	while (stack)
	{
		++pos;
		max = stack->nb;
		if (max == check_max(stack))
			break ;
		stack = stack->next;
	}
	return (pos);
}
