/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:30 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 17:51:04 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_index_str(char *str, char c)
{
	int	idx;

	idx = 0;
	while (str[idx] != c)
	{
		if (str[idx] == '\0')
			return (-1);
		idx++;
	}
	return (idx);
}
