
#ifndef STRUCT_H
# define STRUCT_H
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
	struct s_env	*env_list; // 환경변수 리스트
	char			**env; // ?
	int				last_exit_num; // ?
	pid_t			pid; // 쉘 pid
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

// 미니쉘에서 한 라인 다루는 구조체
typedef struct s_parse
{
	char			*line; // 인풋에 환경변수가 있으면 대치시킨 라인
	char			*input; // 인풋
	struct s_list	*dummys;
	struct s_list	*tokens;
	struct s_cmd	*cmd;
	struct s_type	*type;
}	t_parse;

enum e_token_type
{
	NONE,
	WORD,
	REDIR,
	PIPE
};

typedef enum e_dummy_type
{
	CHAR	= 0x0001,
	_QUOTE	= 0x0002,
	S_QUOTE	= 0x0004,
	D_QUOTE	= 0x0008,
	_REDIR	= 0x0010,
	R_REDIR	= 0x0020,
	L_REDIR	= 0x0040,
	_PIPE	= 0x0100,
	_SPACE	= 0x0200,
	BREAK	= 0x1000,
	ADD_NULL= 0x2000
}	t_dummy_type;

#endif