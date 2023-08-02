/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:48:16 by youngkpa          #+#    #+#             */
/*   Updated: 2023/07/08 01:14:51 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		first_idx;
	int		last_idx;
	int		i;

	first_idx = 0;
	while (ft_c_in_set(*(s1 + first_idx), set))
		first_idx++;
	if (first_idx == ft_strlen(s1))
		return (ft_strdup(""));
	last_idx = ft_strlen(s1) - 1;
	while (ft_c_in_set(*(s1 + last_idx), set))
		last_idx--;
	new_str = malloc(sizeof(char) * (last_idx - first_idx + 2));
	if (new_str == 0)
		return (0);
	i = 0;
	while (i < last_idx - first_idx + 1)
	{
		*(new_str + i) = *(s1 + first_idx + i);
		i++;
	}
	*(new_str + i) = 0;
	return (new_str);
}
