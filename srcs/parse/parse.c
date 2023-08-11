#include "../../includes/minishell.h"

void	parse(t_argv **argvs)
{
	t_parse	info;
	int		err;

	while (TRUE)
	{
		ft_memset(&info, 0, sizeof(t_parse)); // parse 초기화
		if (input_to_line(&info) == FAIL)
			continue ;
		print(info.line);
		// err = create_tokens(&info.tokens, &info.dummys, info.line);
		// if (!err)
		// 	err = create_argvs(argvs, &info.tokens, &info.cmd, &info.type);
		// if (!error_handler(info, err))
		// 	break ;
	}
}
