/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file..c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:26:38 by youngkpa          #+#    #+#             */
/*   Updated: 2023/07/08 01:08:00 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_size;
	char	*str;

	str = ft_strdup("");
	if (str == FT_NULL)
		return (FT_NULL);
	while (TRUE)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(str);
			return (FT_NULL);
		}
		if (read_size == 0)
			break ;
		buf[read_size] = 0;
		str = gnl_strjoin_and_free(str, buf);
	}
	return (str);
}
