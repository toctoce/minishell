/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:41:52 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:41:54 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_open(char *file, int type)
{
	int	fd;

	if (type == RD_T_OUT)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (type == RD_A_OUT)
		fd = open(file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (type == RD_IN)
		fd = open(file, O_RDONLY);
	if (type == RD_HDOC)
		fd = open(file, O_CREAT | O_WRONLY, S_IRUSR);
	if (fd < 0 && g_info.pid != getpid())
		print_error_exit(file, strerror(errno), FAIL);
	if (fd < 0)
	{
		print_error(file, strerror(errno), FAIL);
		return (-1);
	}
	return (fd);
}
