/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:03:01 by youngkpa          #+#    #+#             */
/*   Updated: 2023/02/22 12:01:34 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_converted_len_x(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_x(unsigned int n, char specifier)
{
	char		*str;
	int			i;
	const char	*digit = "0123456789ABCDEF";

	str = malloc(sizeof(char) * (ft_converted_len_x(n) + 1));
	if (str == 0)
		return (0);
	i = ft_converted_len_x(n);
	*(str + i) = '\0';
	if (n == 0)
		*str = '0';
	i--;
	while (n != 0)
	{
		if (specifier == 'x')
			*(str + i) = ft_tolower(digit[n % 16]);
		else
			*(str + i) = digit[n % 16];
		n = n / 16;
		i--;
	}
	return (str);
}

int	ft_spec_x(va_list ap, char specifier)
{
	int		num;
	int		printed_len;
	char	*printed;

	num = va_arg(ap, unsigned long long);
	printed = ft_itoa_x(num, specifier);
	if (!printed)
		return (-1);
	printed_len = ft_strlen(printed);
	if (write(1, printed, printed_len) == -1)
	{
		free(printed);
		return (-1);
	}
	free(printed);
	return (printed_len);
}
