/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:33:31 by youngkpa          #+#    #+#             */
/*   Updated: 2022/11/27 18:38:16 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	idx;

	len = ft_strlen(src);
	idx = 0;
	if (dstsize == 0)
		return (len);
	while (idx < dstsize - 1)
	{
		if (src[idx] == '\0')
			break ;
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (len);
}
