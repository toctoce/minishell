/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:51:31 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 18:04:41 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_error(char *str, int exit_status)
{
	ft_putendl_fd(str, STDERR_FILENO);
	g_info.last_exit_status = exit_status;
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

void	check_malloc_error(void *target)
{
	if (!target)
		exit_shell_by_error("malloc failed");
}
