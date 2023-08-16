/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:34 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 18:06:40 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_token_error(t_parse info, int error)
{
	if (error & ERROR_DUMMIES)
		return (error);
	if (error & ERROR_SYNTAX)
		shell_error("syntax error: unexpected tokens", EXIT_STATUS_FAILURE);
	if (error & ERROR_OCCURED)
		ft_lstclear(&info.tokens, free_token);
	return (error);
}

void	parse(t_argv **argvs)
{
	t_parse	info;
	int		error;

	while (TRUE)
	{
		ft_memset(&info, 0, sizeof(t_parse));
		if (input_to_line(&info) == FAIL)
		{
			ft_lstclear(&info.dummys, free_dummy);
			continue ;
		}
		error = line_to_tokens(&info.tokens, &info.dummys, info.line);
		free(info.line);
		ft_lstclear(&info.dummys, free_dummy);
		if (error & ERROR_OCCURED)
		{
			check_token_error(info, error);
			continue ;
		}
		create_argvs(argvs, info.tokens, &info.cmd, &info.type);
		if (error == ERROR_NO_OCCURED)
			break ;
	}
}
