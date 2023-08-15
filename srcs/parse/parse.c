/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:34 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/15 20:55:42 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_token_error(t_parse info, int error)
{
	free(info.line);
	ft_lstclear(&info.dummys, free_dummy);
	if (error & ERROR_SYNTAX)
		shell_error("syntax error: unexpected tokens", EXIT_STATUS_FAILURE);
	// if (error & ERROR_NO_OCCURED)
	// {
	// 	ft_lstclear(&info.tokens, free_content);
	// }
	// if (error & ERROR_ARGVS)
	// {
	// 	ft_lstclear(&info.tokens, free_token);
	// 	if (info.cmd)
	// 	{
	// 		free_lst_only(&info.cmd->cmds);
	// 		free(info.cmd);
	// 	}
	// 	if (info.type)
	// 		free(info.type);
	// }
	if (error & ERROR_OCCURED)
	{
		ft_lstclear(&info.tokens, free_token);
		return (TRUE);
	}
	return (error);
}

// void print_argv_type(t_argv *argv)
// {
// 	if (argv->in)
// 	{
// 		print("type : in");
// 		ft_putstr_fd("	value : ", 1);
// 		print(argv->in->value);
// 	}
// 	if (argv->out)
// 	{
// 		print("type : out");
// 		ft_putstr_fd("	value : ", 1);
// 		print(argv->out->value);
// 	}
// 	if (argv->hdoc)
// 	{
// 		print("type : hdoc");
// 		ft_putstr_fd("	value : ", 1);
// 		print(argv->hdoc->value);
// 	}
// }

void	parse(t_argv **argvs)
{
	t_parse	info;
	int		error;

	while (TRUE)
	{
		ft_memset(&info, 0, sizeof(t_parse)); // parse 초기화
		if (input_to_line(&info) == FAIL)
			continue ;
		error = line_to_tokens(&info.tokens, &info.dummys, info.line);
		if (error & ERROR_OCCURED)
		{
			print(ft_itoa(error));
			check_token_error(info, error);
		}
		create_argvs(argvs, info.tokens, &info.cmd, &info.type);
		if (error == ERROR_NO_OCCURED)
			break ;
		// t_argv	*argv;
		// char	**cmds;
		// argv = *argvs;
		// while (argv)
		// {
		// 	cmds = argv->cmd;
		// 	print("====== argv ======");
		// 	while (*cmds)
		// 	{
		// 		ft_putstr_fd("cmd는",1);
		// 		print(*cmds);
		// 		cmds++;
		// 	}
		// 	print_argv_type(argv);
		// 	argv = argv->next;
		// }
	}
}
