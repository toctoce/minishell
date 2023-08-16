/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:09:39 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:45:05 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unlink_hdoc(t_argv *argv)
{
	t_argv	*tmp;
	t_redir	*hdoc;

	tmp = argv;
	while (tmp)
	{
		hdoc = tmp->hdoc;
		while (hdoc)
		{
			unlink(hdoc->value);
			hdoc = hdoc->next;
		}
		tmp = tmp->next;
	}
}

static void	read_for_hdoc(int fd, char *name)
{
	char	*line;
	char	*input;

	while (fd > 0)
	{
		input = readline("> ");
		if (!input || ft_strcmp(input, &name[7]) == 0)
		{
			free(input);
			break ;
		}
		replace_env(&line, input);
		ft_putendl_fd(line, fd);
		free(line);
		free(input);
	}
}

static void	run_hdoc(t_redir *hdoc)
{
	int		fd;
	t_redir	*tmp;

	tmp = hdoc;
	while (tmp)
	{
		unlink(tmp->value);
		fd = ft_open(tmp->value, RD_HDOC);
		read_for_hdoc(fd, tmp->value);
		close(fd);
		tmp = tmp->next;
	}
}

static int	make_hdoc(t_argv *argv)
{
	int		status;
	pid_t	pid;
	t_argv	*tmp;

	tmp = argv;
	ignore_signal();
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, hdoc_sigint_handler);
		while (tmp)
		{
			run_hdoc(tmp->hdoc);
			tmp = tmp->next;
		}
		exit (SUCCESS);
	}
	if (pid < 0)
		print_error("fork", strerror(errno), FAIL);
	wait(&status);
	status = status >> 8;
	g_info.last_exit_status = status;
	return (status);
}

int	check_heredoc(t_argv *argv)
{
	t_argv	*tmp;
	int		ishdoc;

	tmp = argv;
	ishdoc = FALSE;
	while (tmp)
	{
		if (tmp->hdoc)
		{
			ishdoc = make_hdoc(argv);
			break ;
		}
		tmp = tmp->next;
	}
	return (ishdoc);
}
