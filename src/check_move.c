/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:59:15 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:53:22 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_median(t_stack *stack)
{
	int	nb;

	nb = count_nb(stack) / 2;
	return (nb);
}

int	check_move(t_stack *stack, int ref)
{
	int	move;
	int	nb;

	move = get_index(stack, ref);
	nb = count_nb(stack);
	if (move > check_median(stack))
		move = nb - move;
	return (move);
}

int	verify_median(int a, int b, int c, int d)
{
	if ((a > b && c > d) || (a <= b && c <= d))
		return (1);
	return (0);
}

int	count_move(t_stack *stack_a, t_stack *stack_b, int ref)
{
	int		target;
	int		move;
	int		median_a;
	int		median_b;

	median_a = check_median(stack_a);
	median_b = check_median(stack_b);
	target = get_target(stack_b, ref);
	if (verify_median(get_index(stack_a, ref), median_a,
			get_index(stack_b, target), median_b))
	{
		if (check_move(stack_a, ref) >= check_move(stack_b, target))
			move = check_move(stack_a, ref);
		else
			move = check_move(stack_b, target);
	}
	else
		move = check_move(stack_a, ref) + check_move(stack_b, target);
	return (move);
}

int	move_min(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	t_stack	*tmp;
	int		nb;

	tmp = stack_a;
	min = count_move(stack_a, stack_b, tmp->nb);
	nb = tmp->nb;
	while (tmp)
	{
		if (min > count_move(stack_a, stack_b, tmp->nb))
		{
			min = count_move(stack_a, stack_b, tmp->nb);
			nb = tmp->nb;
		}
		tmp = tmp->next;
	}
	return (nb);
}
