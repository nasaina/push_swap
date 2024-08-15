/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:56:44 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:53:49 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_print_error(t_stack *stack)
{
	if (stack)
		free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

int	check_space(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] == 32)
		i++;
	if (!str[i])
		return (0);
	return (1);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == 32 || ft_isdigit(str[i]) || str[i] == 45)
			&& check_space(str))
		{
			if ((str[i] == 45 && !ft_isdigit(str[i + 1]))
				|| (str[i] == 45 && ft_isdigit(str[i - 1])))
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	check_digit(int ac, char **av, t_stack *stack)
{
	int	i;

	i = ac - 1;
	while (i >= 1)
	{
		if (!check_str(av[i]))
			ft_print_error(stack);
		i--;
	}
	return (1);
}

int	check_double(t_stack *stack)
{
	t_stack	*current;

	while (stack)
	{
		current = stack->next;
		while (current)
		{
			if (current->nb == stack->nb)
				return (0);
			current = current->next;
		}
		stack = stack->next;
	}
	return (1);
}
