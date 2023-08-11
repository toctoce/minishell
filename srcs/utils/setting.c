/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:49:11 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/11 21:57:03 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    set_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void    unset_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
    // 제어문자 반항 x. ^C 같은거 안나오게 해줌
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
        // 버퍼의 문자를 ""로 대치함.
		rl_replace_line("", 0);
		ft_putstr_fd("\n", STDOUT_FILENO);
        // 개행 후에 new line이라고 알림
		rl_on_new_line();
		rl_redisplay();
		g_info.last_exit_status = 128 + signo; // $?를 위한 코드.
	}
	else if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	set_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}
