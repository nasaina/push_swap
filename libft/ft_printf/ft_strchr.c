/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:55:55 by nandrian          #+#    #+#             */
/*   Updated: 2024/08/15 13:44:02 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr_len(const char *s, int c)
{
	size_t	len;
	char	in;

	len = ft_strlen_len(s);
	in = (char)c;
	while (len > 0 && *s != in)
	{
		s++;
		len--;
	}
	if (*s == in)
		return (1);
	return (0);
}
