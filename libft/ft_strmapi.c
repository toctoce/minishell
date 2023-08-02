/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:45:21 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/15 16:14:33 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*new_str;

	len = ft_strlen(s);
	i = 0;
	new_str = malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (0);
	while (i < len)
	{
		*(new_str + i) = f(i, *(s + i));
		i++;
	}
	*(new_str + i) = '\0';
	return (new_str);
}
