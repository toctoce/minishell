/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:29:47 by youngkpa          #+#    #+#             */
/*   Updated: 2023/05/27 20:13:23 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_free(char **address)
{
	free(*address);
	*address = 0;
}

int	gnl_char_index(const char *str, char c)
{
	int	idx;

	idx = 0;
	while (str[idx] != c)
	{
		if (str[idx] == '\0')
			return (-1);
		idx++;
	}
	return (idx);
}

int	gnl_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*gnl_strdup(char *src, int len)
{
	char	*string;
	int		idx;

	string = (char *)malloc(len + 1);
	if (!string)
		return (ERROR);
	idx = 0;
	while (src[idx] && idx < len)
	{
		string[idx] = src[idx];
		idx++;
	}
	string[idx] = '\0';
	return (string);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		len;
	char	*new_str;
	char	*ptr;

	len = gnl_strlen(s1) + gnl_strlen(s2);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (ERROR);
	ptr = new_str;
	while (*s1)
	{
		*ptr = *s1;
		ptr++;
		s1++;
	}
	while (*s2)
	{
		*ptr = *s2;
		ptr++;
		s2++;
	}
	*ptr = '\0';
	return (new_str);
}
