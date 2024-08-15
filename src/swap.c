/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:37:31 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:58:14 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stack *stack)
{
	ft_swap(&stack->nb, &stack->next->nb);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_b)
{
	ft_swap(&stack_b->nb, &stack_b->next->nb);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(&stack_a->nb, &stack_a->next->nb);
	ft_swap(&stack_b->nb, &stack_b->next->nb);
	ft_putendl_fd("ss", 1);
}
