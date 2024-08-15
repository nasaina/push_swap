/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:33:31 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:50:57 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_int_min_max(char **split, t_stack *stack)
{
	int		i;
	long	result;

	i = 0;
	while (split[i])
	{
		result = ft_atol(split[i], stack);
		if (result > 2147483647 || result < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_split(char **split, t_stack *stack, int *j)
{
	if (!check_int_min_max(split, stack))
	{
		while (*j >= 0)
		{
			free(split[*j]);
			*j -= 1;
		}
		free(split);
		ft_print_error(stack);
	}
}

t_stack	*ft_split_arg(t_stack *stack, char *av)
{
	char	**split;
	int		j;
	long	result;

	if (!ft_strchr(av, ' '))
	{
		result = ft_atol(av, stack);
		if (result > 2147483647 || result < -2147483648)
			ft_print_error(stack);
		add_front(&stack, result);
	}
	else
	{
		j = ft_countw(av, ' ') - 1;
		split = ft_split(av, ' ');
		ft_free_split(split, stack, &j);
		while (j >= 0)
		{
			add_front(&stack, ft_atol(split[j], stack));
			free(split[j]);
			j--;
		}
		free(split);
	}
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = ac - 1;
	check_digit(ac, av, stack);
	if (ac > 1)
	{
		while (i >= 1)
		{
			stack = ft_split_arg(stack, av[i]);
			i--;
		}
		if (check_double(stack) == 0)
			ft_print_error(stack);
		if (!sorted(stack))
			make_sort(&stack);
	}
	free_stack(stack);
	return (0);
}
