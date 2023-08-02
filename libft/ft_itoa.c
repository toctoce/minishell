/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:12:45 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/07 15:52:46 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_converted_len(long long nbr)
{
	long long	len;

	len = 0;
	if (nbr < 0)
	{
		len += 1;
		nbr *= -1;
	}
	else if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long long	nbr;

	nbr = (long long) n;
	str = malloc(sizeof(char) * ft_converted_len(nbr) + 1);
	if (str == 0)
		return (0);
	i = ft_converted_len(nbr);
	*(str + i) = '\0';
	if (nbr < 0)
	{
		*str = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
		*str = '0';
	i--;
	while (nbr > 0)
	{
		*(str + i) = '0' + nbr % 10;
		nbr = nbr / 10;
		i--;
	}
	return (str);
}
