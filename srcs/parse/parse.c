#include "../../includes/minishell.h"

int	is_env(char *input, int *flag)
{
	if (!(*flag & S_QUOTE) && *input == '\"') //큰 따옴표
		*flag ^= D_QUOTE;
	if (!(*flag & D_QUOTE) && *input == '\'') // 작은 따옴표
		*flag ^= S_QUOTE;
	if (!(*flag & S_QUOTE) && *input == '$') // 달러표시가 들어왔으면?
	{
		if (*(input + 1) == '\'' || *(input + 1) == '\"')
			return (FALSE);
		if (ft_isalpha(*(input + 1)) || *(input + 1) == '_')
			return (TRUE);
		if (!ft_isspace(*(input + 1)) && *(input + 1) != '\0')
			return (TRUE);
	}
	return (FALSE);
}

int	get_size(char *input)
{
	int		size;
	int		flag;
	char	*env;

	size = 0;
	flag = 0;
	while (*input)
	{
		if (is_env(input, &flag))
		{
			env = get_env_value(input);
			if (!env)
				return (FALSE);
			size += ft_strlen(env);
			input += get_env_key_len(input + 1) + 1;
			free(env);
		}
		else
		{
			input++;
			size++;
		}
	}
	return (size);
}

// $가 들어오면 abort 발생함
void	handle_env(char **line, char *input)
{
	char	*value;
	int		size;
	int		flag;

	flag = 0;
	size = get_size(input);
	*line = malloc(sizeof(char) * (size + 1));
	if (!(*line))
		exit_shell_by_error("malloc failed");
	while (*input)
	{
		// 이 부분에 들어오면 abort 발생
		if (is_env(input, &flag)) // 환경변수이면 여기 들어와서 처리
		{
			value = get_env_value(input); // 환경변수 value 구함
			ft_strlcat(*line, value, ft_strlen(value) + ft_strlen(*line) + 1); // line에 value + line추가
			input += get_env_key_len(input + 1) + 1; // $USER라면, 5만큼 건너뛰는것임.
			free(value);
		}
		else // 환경변수가 아니면
		{
			ft_strlcat(*line, input, ft_strlen(*line) + 2); // line에서 공백 하나 넣고 붙이기.
			input++;
		}
	}
}

int	handle_input(t_parse *info)
{
	info->input = readline("minishell > "); // 인풋을 input에다가 넣음.
	if (!(info->input)) // ^D 들어올 때
		exit_shell("exit");
	add_history(info->input);
	handle_env(&info->line, info->input);
	free(info->input); // 인풋은 할 일 끝남
	if (all_isspace(info->line) == TRUE)
		return (FAIL);
	return (SUCCESS);
}

void	parse(t_argv **argvs)
{
	t_parse	info;
	int		err;

	while (TRUE)
	{
		ft_memset(&info, 0, sizeof(t_parse)); // parse 초기화
		if (handle_input(&info) == FAIL)
			continue ;
		print(info.line);
		print("\n");
		// err = create_tokens(&info.tokens, &info.dummys, info.line);
		// if (!err)
		// 	err = create_argvs(argvs, &info.tokens, &info.cmd, &info.type);
		// if (!error_handler(info, err))
		// 	break ;
	}
}
