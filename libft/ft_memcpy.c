/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:33:18 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/15 15:16:43 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;

	if (dst == src)
		return (dst);
	ptr = (unsigned char *) dst;
	while (n)
	{
		*ptr = *(unsigned char *)src;
		n--;
		ptr++;
		src++;
	}
	return (dst);
}
