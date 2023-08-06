/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:23:52 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/06 22:37:39 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_info	g_info;

int	main(int argc, char **argv, char **envp)
{
	// t_argv	*argvs;
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("arg error\n", STDERR_FILENO);
		exit(-1);
	}
	g_info.pid = getpid();
	init_env(envp);
	while (TRUE)
	{
		// argvs = NULL;
		set_terminal();
		set_signal();
// 		parse(&argvs);
// 		execute(argvs);
	}
}
