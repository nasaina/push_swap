/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:00:23 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:55:17 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_rrb(t_stack **stack_b, int b, t_stack **stack_a, int a)
{
	while ((*stack_a)->nb != a && (*stack_b)->nb != b)
		rr(stack_a, stack_b);
	while ((*stack_a)->nb != a)
		ra(stack_a);
	while ((*stack_b)->nb != b)
		rb(stack_b);
}

void	do_rrrb(t_stack **stack_b, int b, t_stack **stack_a, int a)
{
	while ((*stack_a)->nb != a && (*stack_b)->nb != b)
		rrr(stack_a, stack_b);
	while ((*stack_a)->nb != a)
		rra(stack_a);
	while ((*stack_b)->nb != b)
		rrb(stack_b);
}

void	do_rotate(t_stack **stack_a, int target_a, t_stack **stack_b, int nb)
{
	if (get_index(*stack_b, nb) <= check_median(*stack_b)
		&& get_index(*stack_a, target_a) > check_median(*stack_a))
	{
		while ((*stack_a)->nb != target_a)
			rra(stack_a);
		while ((*stack_b)->nb != nb)
			rb(stack_a);
	}
	else if (get_index(*stack_b, nb) > check_median(*stack_b)
		&& get_index(*stack_a, target_a) <= check_median(*stack_a))
	{
		while ((*stack_a)->nb != target_a)
			ra(stack_a);
		while ((*stack_b)->nb != nb)
			rrb(stack_a);
	}
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	int	nb;
	int	target_a;

	if (stack_b == NULL)
		return ;
	nb = (*stack_b)->nb;
	target_a = get_target_a(*stack_a, nb);
	if (get_index(*stack_b, nb) > check_median(*stack_b)
		&& get_index(*stack_a, target_a) > check_median(*stack_a))
		do_rrrb(stack_b, nb, stack_a, target_a);
	else if (get_index(*stack_b, nb) <= check_median(*stack_b)
		&& get_index(*stack_a, target_a) <= check_median(*stack_a))
		do_rrb(stack_b, nb, stack_a, target_a);
	else
		do_rotate(stack_a, target_a, stack_b, nb);
	pa(stack_a, stack_b);
}
