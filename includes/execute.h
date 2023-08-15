/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:00:37 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/15 18:09:11 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

void	    execute(t_argv *argv);
static int	init_execute(int *cnt, pid_t **pids, int ***pipes, t_argv *argv);
void	    set_pipe_cnt(int *cnt_pipe, t_argv *argv);
int	        set_pipes(int ***pipes, int cnt_pipe);
void	    close_pipes(int **pipes, int cnt);
void	    free_pipes(int **pipes);
int	        is_builtin(char **cmd);
void    	single_process(t_argv *argv);
int	        set_stdin_redir(t_argv *argv);
int	        set_stdout_redir(t_argv *argv);
void	    reset_stdin(int fd);
void	    reset_stdout(int fd);
void	    run_builtin_process(char **cmd);
void	    run_echo(char **cmd);
void	    run_cd(char **cmd);
void	    run_pwd(char **cmd);
void	    run_export(char **cmd);
int	        is_valid_key(char *key);
void	    run_unset(char **cmd);
void	    run_env(char **cmd);
void	    run_exit(char **cmd);
char		*get_path(char *cmd);
#endif