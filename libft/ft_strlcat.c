/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:33:30 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/15 16:14:31 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	char	*ptr;
	size_t	len_now;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	ptr = dst + dst_len;
	len_now = dst_len;
	if (dst_len >= dstsize || dstsize == 0)
		return (dstsize + src_len);
	while (*src != '\0' && len_now < dstsize - 1)
	{
		*ptr = *src;
		src++;
		ptr++;
		len_now++;
	}
	*ptr = '\0';
	return (dst_len + src_len);
}
