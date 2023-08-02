/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:26:33 by youngkpa          #+#    #+#             */
/*   Updated: 2023/07/08 01:16:59 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*sub_s;
	int		i;

	if (ft_strlen(s) < start)
	{
		sub_s = malloc(1);
		if (!sub_s)
			return (0);
		*sub_s = '\0';
		return (sub_s);
	}
	if (ft_strlen(s) <= start + len)
		len = ft_strlen(s) - start;
	i = 0;
	sub_s = malloc(len + 1);
	if (!sub_s)
		return (0);
	while (i < len)
	{
		*(sub_s + i) = *(s + start + i);
		i++;
	}
	*(sub_s + i) = 0;
	return (sub_s);
}
