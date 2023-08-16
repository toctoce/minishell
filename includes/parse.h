/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:48 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 17:58:07 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "minishell.h"

void	parse(t_argv **argvs);
int		input_to_line(t_parse *info);
int		line_to_tokens(t_list **tokens, t_list **dummys, char *line);
int		create_dummies(t_list **dummy_list, char *line);
void	create_tokens(t_list **tokens, t_list *dummys);
void	create_argvs(t_argv **argvs, t_list *tokens, t_cmd **cmd, \
		t_type **type);
void	add_argv(t_argv **argvs, t_token *token, t_cmd *cmd, t_type *type);
void	add_cmd_to_argvs(t_cmd *cmd, t_argv **argvs);
void	replace_env(char **line, char *input);

#endif