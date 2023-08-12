/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:00:37 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/11 22:45:23 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../libft/libft.h"
# include "parse.h"
# include "util.h"
# include <errno.h>

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

#endif