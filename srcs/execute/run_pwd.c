/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:42:22 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:42:23 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	run_pwd(char **cmd)
{
	char	cwd[PATH_MAX];

	if (cmd[1])
	{
		print_error("pwd", "too many arguments", FAIL);
		return ;
	}
	if (!getcwd(cwd, sizeof(cwd)))
	{
		print_error("pwd", strerror(errno), FAIL);
		return ;
	}
	printf("%s\n", cwd);
}
