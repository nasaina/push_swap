/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:49:51 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:55:37 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pa(t_stack **stack_a, t_stack	**stack_b)
{
	t_stack	*tmp;

	if (!(*stack_b))
		return ;
	tmp = detach_first(stack_b);
	add_front(stack_a, tmp->nb);
	free_stack(tmp);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack	**stack_b)
{
	t_stack	*tmp;

	if (!(stack_a))
		return ;
	if (!*stack_b)
	{
		tmp = detach_first(stack_a);
		add_front(stack_b, tmp->nb);
		free_stack(tmp);
		ft_putendl_fd("pb", 1);
	}
	else
	{
		tmp = detach_first(stack_a);
		tmp->next = *stack_b;
		*stack_b = tmp;
		ft_putendl_fd("pb", 1);
	}
}
