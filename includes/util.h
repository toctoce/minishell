/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:08 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/15 16:19:44 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include "minishell.h"

void	init_env(char **env);
void	exit_shell(char *str);
void	exit_shell_by_error(char *str);
void    unset_echoctl(void);
void	set_signal(void);
t_env	*get_env(char *key);
char	*get_env_value(char *line);
int     get_env_key_len(char *str);
void    free_env(t_env *env);
int     all_isspace(char *line);
void	print_error(char *cmd, char *msg, int err_num);
void	print_error_exit(char *cmd, char *msg, int exit_num);
char	*ft_str_double_join(char *str1, char *str2, char *str3);

#endif