/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:08 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 18:00:46 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include "minishell.h"

void	init_env(char **env);
t_env	*make_env(char *env_line);
void	add_env(t_env **lst, char *env_line);
void	exit_shell(char *str);
void	exit_shell_by_error(char *str);
void	unset_echoctl(void);
void	set_echoctl(void);
void	check_malloc_error(void *target);
void	shell_error(char *str, int exit_status);
void	set_signal(void);
t_env	*get_env(char *key);
char	*get_env_value(char *line);
int		get_env_key_len(char *str);
void	free_env_list(void);
int		all_isspace(char *line);
void	print_error(char *cmd, char *msg, int err_num);
void	print_error_exit(char *cmd, char *msg, int exit_num);
char	*ft_str_double_join(char *str1, char *str2, char *str3);
void	free_str_list(char **str_list);
void	free_content(void *content);
void	free_dummy(void *dummy);
void	free_token(void *token);
void	free_lst(void *lst);
void	free_env(void *env);
void	free_redir(t_redir *redir);
int		ft_redirsize(t_redir *redirs);
t_redir	*ft_redirlast(t_redir *redir);
void	ft_rediradd_back(t_redir **redirs, t_redir *new);
void	free_argv(t_argv *argv);
int		ft_argvsize(t_argv *argvs);
t_argv	*ft_argvlast(t_argv *argv);
void	ft_argvadd_back(t_argv **argvs, t_argv *new);
t_argv	*create_argv(void);
int		get_redir_type(char *value);
t_redir	*create_redir(void);
void	hdoc_sigint_handler(int signo);
void	reset_envp(void);
void	ignore_signal(void);
void	default_signal(void);

#endif