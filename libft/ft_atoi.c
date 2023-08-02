/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:33:02 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/07 15:53:02 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_value(const char *str)
{
	int	value;

	value = 0;
	while (ft_isdigit(*str))
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	return (value);
}

static int	atoi_sign(const char **str)
{
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '+')
	{
		(*str)++;
		return (1);
	}
	else if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (-2147483648);
	sign = atoi_sign(&str);
	value = atoi_value(str);
	return (sign * value);
}
