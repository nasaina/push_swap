/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:07:15 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:54:46 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*create(int n)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->nb = n;
	stack->next = NULL;
	return (stack);
}

t_stack	*lst_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_back(t_stack **stack, int n)
{
	t_stack	*element;
	t_stack	*tmp;

	element = create(n);
	if (*stack)
	{
		tmp = lst_last(*stack);
		tmp->next = element;
	}
	else
		*stack = element;
}

void	add_front(t_stack **stack, int n)
{
	t_stack	*element;

	element = create(n);
	element->next = *stack;
	*stack = element;
}
