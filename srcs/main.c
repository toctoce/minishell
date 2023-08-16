/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:23:52 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 17:40:31 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_info	g_info;

int	main(int argc, char **argv, char **envp)
{
	t_argv	*argvs;

	(void)argv;
	if (argc != 1)
		exit_shell_by_error("invalid argv");
	g_info.pid = getpid();
	init_env(envp);
	while (TRUE)
	{
		argvs = NULL;
		unset_echoctl();
		set_signal();
		parse(&argvs);
		execute(argvs);
	}
}
