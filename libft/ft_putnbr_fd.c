/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:59:24 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/15 15:59:41 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long long nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static int	ft_10_power(int n)
{
	if (n == 0)
		return (1);
	return (10 * ft_10_power(n - 1));
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;
	int			digit;
	int			i;

	nbr = (long long) n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	else if (nbr == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	i = ft_num_len(nbr) - 1;
	digit = ft_10_power(i);
	while (digit > 0)
	{
		ft_putchar_fd('0' + nbr / digit, fd);
		nbr %= digit;
		digit /= 10;
	}
}
