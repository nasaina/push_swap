/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:45:17 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 15:35:10 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*current;

	if (*stack_b == NULL)
		return ;
	tmp = detach_first(stack_b);
	current = *stack_b;
	while (current->next)
		current = current->next;
	current->next = tmp;
}

void	ra(t_stack **stack)
{
	rotate(stack);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || *stack_a == NULL)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
