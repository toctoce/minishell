/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:33:13 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/06 21:04:11 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
// OK
char	*get_env_value(char *line)
{
	char	*key;
	t_env	*env;
	key = ft_substr(line, 1, get_env_key_len(line + 1));
	if (!key)
		exit_shell_by_error("malloc failed");
	env = get_env(key);
	if (env == NULL)
		return ("");
	free(key);
	return (env->value);
}

// OK
int	get_env_key_len(char *str)
{
	int	i;

	i = 0;
	// ?일때는 마지막 exit status
	// $일때는 pid
	if (str[i] == '$' || str[i] == '?')
		return (1);
	// 첫 번째 글자는 숫자일 수 없음.
	if (ft_isdigit(str[i]))
		return (0);
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	return (i);
}

// OK
t_env	*get_env(char *key)
{
	t_env	*env_list;

	env_list = g_info.env_list;
	while (env_list)
	{
		if (ft_strcmp(env_list->key, key) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}

t_env	*make_env(char *env_line)
{
	t_env	*new_env;
	int		seperator_idx;
	char	*value;

	new_env = (t_env *)malloc(sizeof(t_env));
	// = 기준으로 나눔.
	seperator_idx = ft_index_str(env_line, '=');
	new_env->key = ft_strndup(env_line, seperator_idx);
	value = env_line + seperator_idx + 1;
	if (ft_strcmp(new_env->key, "SHLVL") == 0)
		new_env->value = ft_strdup(ft_itoa(ft_atoi(value) + 1));
	else
		new_env->value = ft_strdup(env_line + seperator_idx + 1);
	new_env->next = NULL;
	new_env->prev = NULL;
	return (new_env);
}

void	add_env(t_env **lst, char *env_line)
{
	t_env	*new_env;
	t_env	*tmp;

	tmp = *lst;
	new_env = make_env(env_line);
	if (!(*lst))
		(*lst) = new_env;
	else
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		new_env->prev = *lst;
		(*lst)->next = new_env;
		(*lst) = (*lst)->next;
	}
	while ((*lst)->prev)
		(*lst) = (*lst)->prev;
}

void	init_env(char **envp)
{
	int		next_leve;
	t_env	*env_list;

	env_list = NULL;
	while (*envp)
	{
		add_env(&env_list, *envp);
		envp++;
	}
	g_info.env_list = env_list;
}
