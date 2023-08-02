/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:50:57 by youngkpa          #+#    #+#             */
/*   Updated: 2023/06/29 20:28:10 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spec_c(va_list ap)
{
	char	printed;

	printed = va_arg(ap, int);
	if (write(1, &printed, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_spec_s(va_list ap)
{
	char	*printed;

	printed = va_arg(ap, char *);
	if (!printed)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	if (write(1, printed, ft_strlen(printed)) == -1)
		return (-1);
	return (ft_strlen(printed));
}

static int	ft_spec_symbol_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

int	ft_handle_specifier(char specifier, va_list ap)
{
	int	add_len;

	add_len = -1;
	if (specifier == 'c')
		add_len = ft_spec_c(ap);
	else if (specifier == 's')
		add_len = ft_spec_s(ap);
	else if (specifier == 'p')
		add_len = ft_spec_p(ap);
	else if (specifier == 'd' || specifier == 'i')
		add_len = ft_spec_di(ap);
	else if (specifier == 'u')
		add_len = ft_spec_u(ap);
	else if (specifier == 'x' || specifier == 'X')
		add_len = ft_spec_x(ap, specifier);
	else if (specifier == '%')
		add_len = ft_spec_symbol_percent();
	else
		return (-1);
	if (add_len == -1)
		return (-1);
	else
		return (add_len);
}
