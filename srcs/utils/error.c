/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:51:31 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/15 15:57:49 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_error(char *cmd, char *msg, int err_num)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	g_info.last_exit_status = err_num;
}

void	print_error_exit(char *cmd, char *msg, int exit_num)
{
	print_error(cmd, msg, exit_num);
	exit(exit_num);
}

void	exit_shell(char *str)
{
	ft_putendl_fd(str, STDOUT_FILENO);
	exit(0);
}

void	exit_shell_by_error(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	exit(-1);
}
