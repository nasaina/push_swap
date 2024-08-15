/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:45:02 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 16:36:22 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_sign(const char *str, t_stack *stack, int *i)
{
	int	sign;

	sign = 1;
	if (!str[*i])
	{
		ft_print_error(stack);
		return (0);
	}
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-')
	{
		sign = -1;
		*i += 1;
	}
	else if (str[*i] == '+')
		*i += 1;
	return (sign);
}

long	ft_atol(const char *str, t_stack *stack)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = check_sign(str, stack, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result = result * sign;
	return (result);
}
