/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:31:26 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:55:28 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_rrr(t_stack **stack_a, int a, t_stack **stack_b, int b)
{
	while ((*stack_a)->nb != a && (*stack_b)->nb != b)
		rrr(stack_a, stack_b);
	while ((*stack_a)->nb != a)
		rra(stack_a);
	while ((*stack_b)->nb != b)
		rrb(stack_b);
}

void	do_rr(t_stack **stack_a, int a, t_stack **stack_b, int b)
{
	while ((*stack_a)->nb != a && (*stack_b)->nb != b)
		rr(stack_a, stack_b);
	while ((*stack_a)->nb != a)
		ra(stack_a);
	while ((*stack_b)->nb != b)
		rb(stack_b);
}

void	rotate_one(t_stack **stack_a, int nb, t_stack **stack_b, int target)
{
	if (get_index(*stack_b, target) <= check_median(*stack_b)
		&& get_index(*stack_a, nb) > check_median(*stack_a))
	{
		while ((*stack_b)->nb != target)
			rb(stack_b);
		while ((*stack_a)->nb != nb)
			rra(stack_a);
	}
	else if (get_index(*stack_b, target) > check_median(*stack_b)
		&& get_index(*stack_a, nb) <= check_median(*stack_a))
	{
		while ((*stack_b)->nb != target)
			rrb(stack_b);
		while ((*stack_a)->nb != nb)
			ra(stack_a);
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	nb;
	int	target;

	nb = move_min(*stack_a, *stack_b);
	target = get_target(*stack_b, nb);
	if (get_index(*stack_a, nb) > check_median(*stack_a)
		&& get_index(*stack_b, target) > check_median(*stack_b))
		do_rrr(stack_a, nb, stack_b, target);
	else if (get_index(*stack_a, nb) <= check_median(*stack_a)
		&& get_index(*stack_b, target) <= check_median(*stack_b))
		do_rr(stack_a, nb, stack_b, target);
	else
		rotate_one(stack_a, nb, stack_b, target);
	pb(stack_a, stack_b);
}
