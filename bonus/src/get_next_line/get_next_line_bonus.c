/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:37:34 by iabkadri          #+#    #+#             */
/*   Updated: 2022/11/04 11:19:14 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_fillbuf(int fd, char **line, char **stock, char **buffer);
char	*join(char *stock, char *buffer);
char	*ft_getline(char **stock, int indx);
int		ft_getindex(char *stock);

char	*get_next_line(int fd)
{
	static char	*stock[OPEN_MAX];
	char		*buffer;
	char		*line;
	int			indx;
	int			i;

	if (fd < 0)
		return (NULL);
	indx = ft_getindex(stock[fd]);
	while (indx == -1)
	{
		i = ft_fillbuf(fd, &line, &stock[fd], &buffer);
		if (i == 0)
			return (line);
		else if (i == -1)
			return (NULL);
		stock[fd] = join(stock[fd], buffer);
		free(buffer);
		indx = ft_getindex(stock[fd]);
	}
	line = ft_getline(&stock[fd], ++indx);
	return (line);
}

int	ft_fillbuf(int fd, char **line, char **stock, char **buffer)
{
	int	i;

	*buffer = malloc(BUFFER_SIZE + 1);
	if (*buffer == NULL)
		return (-1);
	i = read(fd, *buffer, BUFFER_SIZE);
	if (i <= 0)
	{
		free(*buffer);
		*buffer = NULL;
		if (*stock != NULL && **stock != '\0' && i == 0)
		{
			*line = ft_strdup(*stock);
			free(*stock);
			*stock = NULL;
			return (0);
		}
		free(*stock);
		*stock = NULL;
		return (-1);
	}
	(*buffer)[i] = '\0';
	return (i);
}

char	*join(char *stock, char *buffer)
{
	char	*p;
	size_t	size;

	if (stock == NULL)
		return (ft_strdup(buffer));
	size = ft_strlen(stock) + ft_strlen(buffer) + 1;
	p = malloc(size);
	if (p == NULL)
	{
		free(stock);
		return (NULL);
	}
	ft_strlcpy(p, stock, size);
	ft_strlcat(p, buffer, size);
	free(stock);
	return (p);
}

char	*ft_getline(char **stock, int indx)
{
	char	*line;
	char	*tmp;

	tmp = ft_strdup(*stock + indx);
	line = ft_substr(*stock, 0, indx);
	free(*stock);
	*stock = tmp;
	return (line);
}

int	ft_getindex(char *stock)
{
	int	i;

	if (stock == NULL)
		return (-1);
	i = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		return (i);
	return (-1);
}
