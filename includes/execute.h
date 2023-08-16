/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:00:37 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 18:07:20 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

void		execute(t_argv *argv);
void		set_pipe_cnt(int *cnt_pipe, t_argv *argv);
int			set_pipes(int ***pipes, int cnt_pipe);
void		close_pipes(int **pipes, int cnt);
void		free_pipes(int **pipes);
int			is_builtin(char **cmd);
void		single_process(t_argv *argv);
int			set_stdin_redir(t_argv *argv);
int			set_stdout_redir(t_argv *argv);
void		set_stdin_pipe(int **pipes, int num);
void		set_stdout_pipe(t_argv *argv, int **pipes, int num);
void		reset_stdin(int fd);
void		reset_stdout(int fd);
void		run_builtin_process(char **cmd);
void		run_echo(char **cmd);
void		run_cd(char **cmd);
void		run_pwd(char **cmd);
void		run_export(char **cmd);
int			is_valid_key(char *key);
void		run_unset(char **cmd);
void		run_env(char **cmd);
void		run_exit(char **cmd);
char		*get_path(char *cmd);
void		multi_process(t_argv *argv, pid_t *pids, int **pipes, int cnt_pipe);
int			ft_open(char *file, int type);
void		unlink_hdoc(t_argv *argv);
int			check_heredoc(t_argv *argv);

#endif