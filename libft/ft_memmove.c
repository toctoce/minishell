/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:33:20 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/15 15:31:37 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	else if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len--)
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
		return (dst);
	}
}
