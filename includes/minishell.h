/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:19:51 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/06 22:02:46 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <readline/readline.h>
# include "../libft/libft.h"
# include "util.h"

# define FAIL 4
// 환경변수 연결리스트
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_info
{
	struct s_env	*env_list; //환경변수 리슽트
	char			**env;
	int				last_exit_num;
	pid_t			pid; // 쉘 pid
}	t_info;

extern t_info	g_info;

#endif