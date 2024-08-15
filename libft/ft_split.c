/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:07:14 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/16 13:59:29 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countw(char const *s, char c)
{
	int	i;
	int	wrd;

	i = 0;
	wrd = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			wrd++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (wrd);
}

static int	ft_splitword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_tab(char const *str, char sep)
{
	char	*tab;
	int		i;
	int		len_t;

	i = 0;
	len_t = ft_splitword(str, sep);
	tab = malloc(sizeof(char) * (len_t + 1));
	if (!tab)
		return (NULL);
	while (i < len_t)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		size;

	size = ft_countw(s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			str[i] = ft_tab(s, c);
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	str[i] = 0;
	return (str);
}
