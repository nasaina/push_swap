/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:38:46 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 17:00:17 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reset_stack(t_stack **stack, t_stack *stack_b)
{
	int	s;

	s = count_nb(stack_b);
	while (s > 0)
	{
		push_a(&stack_b, stack);
		s--;
	}
	while ((*stack)->nb != check_min(*stack))
	{
		if (get_index(*stack, check_min(*stack)) > check_median(*stack))
			rra(stack);
		else
			ra(stack);
	}
}

void	sort(t_stack **stack)
{
	t_stack	*stack_b;
	int		i;
	int		j;

	i = 0;
	stack_b = NULL;
	while (i < 2)
	{
		pb(stack, &stack_b);
		i++;
	}
	j = count_nb(*stack);
	while (j > 3)
	{
		push_b(stack, &stack_b);
		j--;
	}
	if (!sorted(*stack))
		sort_three(stack);
	reset_stack(stack, stack_b);
}
