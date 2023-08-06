/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:23:52 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/06 15:38:51 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_info	g_info;

int	main(int argc, char **argv, char **envp)
{
	// t_argv	*argvs;
    // while( *envp)
    //     printf( "%s\n\n\n", *envp++);
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("arg error\n", STDERR_FILENO);
		exit(-1);
	}
	g_info.pid = getpid();
	init_env(envp);
// 	while (1)
// 	{
// 		argvs = NULL;
// 		unset_echoctl();
// 		main_signal();
// 		parse(&argvs);
// 		execute(argvs);
// 	}
}
