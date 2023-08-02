/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:26:12 by youngkpa          #+#    #+#             */
/*   Updated: 2023/05/27 20:13:25 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin_and_free(char *storage, char *buf)
{
	char	*ret;

	ret = gnl_strjoin(storage, buf);
	if (ret == ERROR)
	{
		gnl_free(&storage);
		return (ERROR);
	}
	gnl_free(&storage);
	return (ret);
}

int	gnl_new_storage(int line_len, char **storage, int is_eof)
{
	int		storage_len;
	char	*new_storage;

	if (is_eof == TRUE)
		gnl_free(storage);
	else
	{
		storage_len = gnl_strlen(*storage) - line_len;
		new_storage = gnl_strdup((*storage + line_len), storage_len);
		gnl_free(storage);
		if (new_storage == ERROR)
			return (ERROR);
		*storage = new_storage;
	}
	return (SUCCESS);
}

char	*gnl_get_line(char **storage)
{
	char	*line;
	int		line_len;
	int		is_eof;

	is_eof = (gnl_char_index(*storage, '\n') == -1);
	if (is_eof)
		line_len = gnl_strlen(*storage);
	else
		line_len = gnl_char_index(*storage, '\n') + 1;
	line = gnl_strdup(*storage, line_len);
	if (line == ERROR)
	{
		gnl_free(storage);
		return (0);
	}
	if (gnl_new_storage(line_len, storage, is_eof) == ERROR)
	{
		gnl_free(&line);
		gnl_free(storage);
		return (0);
	}
	return (line);
}

int	gnl_handle_exception(int size, char **storage)
{
	if (size < 0 || (size == 0 && (**storage) == '\0'))
	{
		gnl_free(storage);
		return (ERROR);
	}
	return (SUCCESS);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAXI];
	char		buf[BUFFER_SIZE + 1];
	int			size;

	if ((fd < 0) || (fd > OPEN_MAXI) || (BUFFER_SIZE <= 0))
		return (0);
	if (storage[fd] == 0)
	{
		storage[fd] = gnl_strdup("", 0);
		if (storage[fd] == ERROR)
			return (0);
	}
	while (gnl_char_index(storage[fd], '\n') == -1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (gnl_handle_exception(size, &storage[fd]) == ERROR)
			return (0);
		if (size == 0)
			break ;
		buf[size] = '\0';
		storage[fd] = gnl_strjoin_and_free(storage[fd], buf);
		if (storage[fd] == ERROR)
			return (0);
	}
	return (gnl_get_line(&storage[fd]));
}
