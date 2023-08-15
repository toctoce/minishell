/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:09:39 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/15 19:40:44 by dohyunki         ###   ########.fr       */
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
		if (!input || ft_strcmp(input, &name[7]) == SUCCESS) // 식별자와 같은지 확인 /tmp/ .0($NAME)
		{
			free(input);
			break ;
		}
		if (replace_env_hdoc(&line, input))
			ft_error_exit("hdoc", "error", FAIL);
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
		unlink(tmp->value); // 있으면 삭제
		fd = ft_open(tmp->value, RD_HDOC); //없으면 만들고 WRONLY
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
	ignore_signal(); // 현재 프로세스가 자식 프로세스를 생성하고 종료를 기다리는 동안의 시그널 상태로 설정
	pid = fork();
	if (pid == 0) // 성공
	{
		signal(SIGINT, hdoc_sigint_handler); // SIGINT 발생하면 표준출력 ""출력 후 종료
		while (tmp)
		{
			run_hdoc(tmp->hdoc);
			tmp = tmp->next;
		}
		exit (SUCCESS);
	}
	if (pid < 0) // 실패
		ft_error("fork", strerror(errno), FAIL);
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
	ishdoc = SUCCESS;
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