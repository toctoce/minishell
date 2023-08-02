/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:40:16 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/12 22:49:02 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup_split(const char *src, char c)
{
	char	*dup;
	int		src_len;
	int		idx;

	src_len = 0;
	while (src[src_len] != c && src[src_len] != '\0')
		src_len++;
	dup = (char *)malloc(sizeof(char) * src_len + 1);
	if (!dup)
		return (0);
	idx = 0;
	while (idx < src_len)
	{
		dup[idx] = src[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}

static int	count_word(const char *str, char c)
{
	int	is_word;
	int	cnt;

	is_word = 0;
	cnt = 0;
	while (*str != '\0')
	{
		if (!is_word && *str != c)
		{
			is_word = 1;
			cnt++;
		}
		else if (is_word && *str == c)
			is_word = 0;
		str++;
	}
	return (cnt);
}

static void	ft_split_free(char **strs, int idx)
{
	while (idx >= 0)
	{
		free(strs[idx]);
		idx--;
	}
	free(strs);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		cnt_word;
	int		idx;

	cnt_word = count_word(s, c);
	strs = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	if (!strs)
		return (0);
	idx = 0;
	while (idx < cnt_word)
	{
		while (*s == c)
			s++;
		strs[idx] = ft_strdup_split(s, c);
		if (!strs[idx])
			ft_split_free(strs, idx);
		s += ft_strlen(strs[idx]);
		idx++;
	}
	strs[idx] = 0;
	return (strs);
}
