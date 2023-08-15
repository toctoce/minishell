/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:08 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/13 03:55:08 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include "minishell.h"

void	init_env(char **env);
void	exit_shell(char *str);
void	exit_shell_by_error(char *str);
void	check_malloc_error(void *target);
void	shell_error(char *str, int exit_status);
void    set_terminal(void);
void	set_signal(void);
t_env	*get_env(char *key);
char	*get_env_value(char *line);
int     get_env_key_len(char *str);
void    free_env(t_env *env);
int     all_isspace(char *line);
// void	free_lst_only(t_list **lst);
void	free_content(void *content);
void	free_dummy(t_dummy *dummy);
void	free_token(t_token *token);
void	free_redir(t_redir *redir);
int     ft_redirsize(t_redir *redirs);
t_redir	*ft_redirlast(t_redir *redir);
void	ft_rediradd_back(t_redir **redirs, t_redir *new);
void	free_argv(t_argv *argv);
int	    ft_argvsize(t_argv *argvs);
t_argv	*ft_argvlast(t_argv *argv);
void	ft_argvadd_back(t_argv **argvs, t_argv *new);
t_argv	*create_argv(void);
int	get_redir_type(char *value);
t_redir	*create_redir(void);

#endif