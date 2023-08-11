/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:23:52 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/11 21:54:40 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_info	g_info;

void print(char *str)
{
	ft_putendl_fd(str, STDOUT_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	t_argv	*argvs; // 미니쉘에서 받는 한 라인에 관련된 변수

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
// 		execute(argvs);
	}
}
