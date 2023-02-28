/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:51:12 by iabkadri          #+#    #+#             */
/*   Updated: 2022/10/24 09:45:19 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_word(const char *s, char c);
static size_t	get_len(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = count_word(s, c);
	str = malloc(size * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
			*str++ = ft_substr(s, 0, get_len(s, c));
		while (*s != '\0' && *s != c)
			s++;
	}
	*str = NULL;
	return (str - size + 1);
}

static size_t	count_word(const char *s, char c)
{
	size_t	cnt;

	cnt = 1;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
			cnt++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (cnt);
}

static size_t	get_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}
