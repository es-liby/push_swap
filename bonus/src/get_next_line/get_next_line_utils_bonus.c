/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:53:17 by iabkadri          #+#    #+#             */
/*   Updated: 2022/11/04 09:43:39 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	size = len + 1;
	slen = ft_strlen(s);
	if (slen < len)
		size = slen + 1;
	if (slen <= start)
		size = 1;
	substr = malloc(size);
	if (substr != NULL)
		ft_strlcpy(substr, s + start, size);
	return (substr);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	size;

	size = ft_strlen(s) + 1;
	p = malloc(size);
	if (p != NULL)
		ft_strlcpy(p, s, size);
	return (p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;

	slen = ft_strlen(src);
	if (dstsize != 0)
	{
		while (*src != '\0' && --dstsize > 0)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (slen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dlen >= dstsize)
		return (dstsize + slen);
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && dstsize-- > dlen + 1)
		*dst++ = *src++;
	*dst = '\0';
	return (dlen + slen);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
