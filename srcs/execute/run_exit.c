/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:42:13 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:47:00 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_atouc(char *str)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str && ((*str == '-') || (*str == '+')))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (ft_isdigit(*str) == FALSE)
		return (-1);
	while (*str && ft_isdigit(*str) == TRUE)
	{
		ret = ret * 10 + (*str - 48);
		if (ret * sign > 2147483647 || ret * sign < -2147483648)
			return (-1);
		str++;
	}
	if (*str && ft_isdigit(*str) == FALSE)
		return (-1);
	return ((unsigned char)(ret * sign));
}

void	run_exit(char **cmd)
{
	int	exit_num;

	if (cmd[1] && cmd[2])
	{
		print_error("exit", "too many arguments", FAIL);
		return ;
	}
	if (cmd[1])
		exit_num = ft_atouc(cmd[1]);
	else
		exit_num = g_info.last_exit_status;
	if (g_info.pid == getpid())
		printf("exit\n");
	if (exit_num < 0)
		print_error("exit", "numeric argument required", 255);
	exit(exit_num);
}
