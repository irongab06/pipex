/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:35:03 by gacavali          #+#    #+#             */
/*   Updated: 2024/05/09 15:44:21 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_read(int *len, int fd, char *buffer)
{
	*len = read(fd, buffer, BUFFER_SIZE);
	return (*len);
}

char	*get_line(char **leftover)
{
	char	*new_line;
	char	*temp;
	size_t	len;

	len = ft_strchr(*leftover, '\n') - *leftover + 1;
	new_line = ft_substr(*leftover, 0, len);
	temp = ft_substr(*leftover, len, ft_strlen(*leftover) - len);
	free(*leftover);
	*leftover = NULL;
	if (temp != NULL)
		*leftover = ft_strjoin(NULL, temp);
	free(temp);
	return (new_line);
}

char	*get_entire_line(char *buffer, char *leftover, int fd)
{
	char	*temp;
	int		len;

	len = 0;
	temp = NULL;
	while (!ft_strchr(leftover, '\n') && ft_read(&len, fd, buffer) > 0)
	{
		buffer[len] = '\0';
		temp = ft_strjoin(leftover, buffer);
		if (leftover)
			free(leftover);
		leftover = ft_strjoin(NULL, temp);
		free(temp);
	}
	if (len < 0)
		return (NULL);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	leftover = get_entire_line(buffer, leftover, fd);
	line = get_line(&leftover);
	if (!ft_strlen(leftover))
	{
		free(leftover);
		leftover = NULL;
	}
	return (line);
}
