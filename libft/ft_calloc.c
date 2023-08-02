/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:18:03 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/12 18:50:36 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	if (count * size != (size_t) count * size)
		return (0);
	memory = malloc(count * size);
	if (memory == 0)
		return (0);
	i = 0;
	while (i < count * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
