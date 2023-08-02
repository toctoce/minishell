/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:33:37 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/15 15:48:36 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;

	if (*needle == '\0')
		return ((char *) haystack);
	if (*haystack == '\0')
		return (0);
	cnt = 0;
	while (*haystack != '\0' && (cnt + ft_strlen(needle)) <= len)
	{
		if (!ft_strncmp(haystack, needle, ft_strlen(needle)))
			return ((char *) haystack);
		haystack++;
		cnt++;
	}
	return (0);
}
