/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:32 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/11 21:44:06 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_env(char *input, int *flag)
{
	if (!(*flag & DM_S_QUOTE) && *input == '\"') //큰 따옴표
		*flag ^= DM_D_QUOTE;
	if (!(*flag & DM_D_QUOTE) && *input == '\'') // 작은 따옴표
		*flag ^= DM_S_QUOTE;
	if (!(*flag & DM_S_QUOTE) && *input == '$') // 달러표시가 들어왔으면?
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

static int	get_size(char *input)
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

static void	replace_env(char **line, char *input)
{
	char	*value;
	int		size;
	int		flag;

	flag = DM_NONE;
	size = get_size(input);
	*line = malloc(sizeof(char) * (size + 1));
	if (!(*line))
		exit_shell_by_error("malloc failed");
	while (*input)
	{
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

int	input_to_line(t_parse *info)
{
	info->input = readline("minishell > "); // 인풋을 input에다가 넣음.
	if (!(info->input)) // ^D 들어올 때
		exit_shell("exit");
	add_history(info->input);
	replace_env(&info->line, info->input);
	free(info->input); // 인풋은 할 일 끝남
	if (all_isspace(info->line) == TRUE)
	{
		free(info->line);
		return (FAIL);
	}
	return (SUCCESS);
}
