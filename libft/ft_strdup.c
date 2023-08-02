/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:33:29 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/15 16:02:31 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*memory;
	int		s1_len;
	int		idx;

	s1_len = ft_strlen(s1);
	memory = malloc(sizeof(char) * (s1_len + 1));
	if (!memory)
		return (0);
	idx = 0;
	while (idx < s1_len)
	{
		memory[idx] = s1[idx];
		idx++;
	}
	memory[idx] = '\0';
	return (memory);
}
