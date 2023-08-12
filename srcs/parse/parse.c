/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:34 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/13 01:10:12 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parse(t_argv **argvs)
{
	t_parse	info;
	int		err;

	while (TRUE)
	{
		ft_memset(&info, 0, sizeof(t_parse)); // parse 초기화
		if (input_to_line(&info) == FAIL)
			continue ;
		err = line_to_tokens(&info.tokens, &info.dummys, info.line);
		if (err & (ERROR_OCCURED))
		{
			print("continue");
			continue;
		}
		// if (!err)
		// 	err = create_argvs(argvs, &info.tokens, &info.cmd, &info.type);
		// if (!error_handler(info, err))
		// 	break ;
	}
}
