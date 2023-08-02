/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:33:39 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/15 16:17:40 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s + ft_strlen(s);
	while (*ptr != (char) c)
	{
		if (ptr != s)
			ptr--;
		else if (*ptr == (char) c)
			return (ptr);
		else
			return (0);
	}
	return (ptr);
}
