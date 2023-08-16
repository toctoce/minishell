/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:14:04 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 17:51:11 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int len)
{
	char	*string;
	int		idx;

	string = (char *)malloc(len + 1);
	if (!string)
		return (FT_NULL);
	idx = 0;
	while (src[idx] && idx < len)
	{
		string[idx] = src[idx];
		idx++;
	}
	string[idx] = '\0';
	return (string);
}
