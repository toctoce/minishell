/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:42:49 by youngkpa          #+#    #+#             */
/*   Updated: 2023/06/29 20:28:36 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	int		add_len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			add_len = ft_handle_specifier(*(++format), ap);
			if (add_len == -1)
				return (-1);
			len += add_len;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
