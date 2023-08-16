/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:50 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 17:59:58 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "minishell.h"

enum e_error_type
{
	ERROR_DUMMIES		= 0x01,
	ERROR_TOKENS		= 0x02,
	ERROR_SYNTAX		= 0x08,
	ERROR_NO_OCCURED	= 0X00,
	ERROR_OCCURED		= (ERROR_DUMMIES | ERROR_TOKENS | ERROR_SYNTAX)
};

enum e_redir_type
{
	RD_NONE,
	RD_T_OUT,
	RD_A_OUT,
	RD_IN,
	RD_HDOC
};

enum e_token_type
{
	TK_NONE,
	TK_WORD,
	TK_REDIR,
	TK_PIPE
};

enum e_exit_status_type
{
	EXIT_STATUS_SUCCESS = 0,
	EXIT_STATUS_FAILURE = 1,
	EXIT_STATUS_COMMAND_NOT_FOUND = 127
};

typedef enum e_dummy_type
{
	DM_NONE	= 0x0001,
	DM_CHAR	= 0x0002,
	DM_S_QUOTE	= 0x0004,
	DM_D_QUOTE	= 0x0008,
	DM_QUOTE	= (DM_S_QUOTE | DM_D_QUOTE),
	DM_R_REDIR	= 0x0010,
	DM_L_REDIR	= 0x0020,
	DM_REDIR	= (DM_R_REDIR | DM_L_REDIR),
	DM_PIPE	= 0x0100,
	DM_SPACE	= 0x0200,
	DM_END	= 0x1000,
	DM_ADD_NULL= 0x2000
}	t_dummy_type;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_info
{
	struct s_env	*env_list;
	char			**envp;
	int				last_exit_status;
	pid_t			pid;
}	t_info;

typedef struct s_redir
{
	int				type;
	char			*value;
	struct s_redir	*next;
}	t_redir;

typedef struct s_argv
{
	char			**cmd;
	struct s_redir	*in;
	struct s_redir	*out;
	struct s_redir	*hdoc;
	struct s_argv	*next;
}	t_argv;

typedef struct s_parse
{
	char			*line;
	char			*input;
	struct s_list	*dummys;
	struct s_list	*tokens;
	struct s_cmd	*cmd;
	struct s_type	*type;
}	t_parse;

typedef struct s_dummy_info
{
	int		type;
	int		size;
	char	*addr;
}	t_dummy_info;

typedef struct s_dummy
{
	int		type;
	char	*value;
}	t_dummy;

typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

typedef struct s_cmd
{
	int				cnt;
	struct s_list	*cmds;
}	t_cmd;

typedef struct s_type
{
	int	last;
	int	redir;
}	t_type;

#endif