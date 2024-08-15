/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:34:21 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 17:00:51 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	sorted(t_stack *stack)
{
	if (stack->next == NULL || stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **stack)
{
	int	pos;

	pos = check_pos_max(*stack);
	if (pos == 1)
	{
		ra(stack);
		if (!sorted(*stack))
			sa(*stack);
	}
	else if (pos == 2)
	{
		rra(stack);
		if (!sorted(*stack))
			sa(*stack);
	}
	else
		sa(*stack);
}

void	sort_push(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	len;

	i = 0;
	len = count_nb(*stack_b);
	if (!sorted(*stack_a))
		sort_three(stack_a);
	while (i < len)
	{
		pa(stack_a, stack_b);
		i++;
	}
}

void	make_sort(t_stack **stack)
{
	if (count_nb(*stack) == 2)
		sa(*stack);
	else if (count_nb(*stack) == 3)
		sort_three(stack);
	else if (count_nb(*stack) >= 4)
		sort(stack);
}
