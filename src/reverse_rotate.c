/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:46:14 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 15:27:21 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	tmp = detach_last(stack);
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
