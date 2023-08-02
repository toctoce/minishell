/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:15:02 by youngkpa          #+#    #+#             */
/*   Updated: 2023/06/29 20:28:22 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_converted_len_p(unsigned long long nbr)
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

char	*ft_itoa_p(unsigned long long n)
{
	char		*str;
	int			i;
	const char	*digit = "0123456789abcdef";

	str = malloc(sizeof(char) * (ft_converted_len_p(n) + 1));
	if (str == 0)
		return (0);
	i = ft_converted_len_p(n);
	*(str + i) = '\0';
	if (n == 0)
		*str = '0';
	i--;
	while (n != 0)
	{
		*(str + i) = digit[n % 16];
		n = n / 16;
		i--;
	}
	return (str);
}

int	ft_spec_p(va_list ap)
{
	long long		num;
	int				printed_len;
	char			*printed;

	num = va_arg(ap, long long);
	if (write(1, "0x", 2) == -1)
		return (-1);
	printed = ft_itoa_p(num);
	if (!printed)
		return (-1);
	printed_len = ft_strlen(printed);
	if (write(1, printed, printed_len) == -1)
	{
		free(printed);
		return (-1);
	}
	free(printed);
	return (2 + printed_len);
}
