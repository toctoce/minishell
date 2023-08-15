/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:33:13 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/15 19:12:14 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_env_list_size(void)
{
	int		idx;
	t_env	*env_lst;

	idx = 0;
	env_lst = g_info.env_list;
	while (env_lst)
	{
		if (env_lst->value)
			idx++;
		env_lst = env_lst->next;
	}
	return (idx);
}

void	reset_envp(void)
{
	t_env	*env_lst;
	char	**env_arr;
	int		lst_size;
	int		idx;

	free_str_list(g_info.envp);
	lst_size = get_env_list_size();
	env_lst = g_info.env_list;
	idx = 0;
	env_arr = malloc(sizeof(char *) * (lst_size + 1));
	check_malloc_error(env_arr);
	while (env_lst)
	{
		if (env_lst->value)
			env_arr[idx] = ft_str_double_join(env_lst->key, \
												"=", env_lst->value);
		env_lst = env_lst->next;
		idx++;
	}
	env_arr[idx] = NULL;
	g_info.envp = env_arr;
}

int	is_valid_key(char *key)
{
	int	idx;

	idx = 0;
	if (!(ft_isalpha(key[idx]) || key[idx] == '_'))
		return (FALSE);
	idx++;
	while (key[idx] && key[idx] != '=')
	{
		if (!(ft_isalnum(key[idx]) || key[idx] == '_'))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

char	*get_env_value(char *line)
{
	char	*key;
	char	*value;
	t_env	*env;

	key = ft_substr(line, 1, get_env_key_len(line + 1));
	if (!key)
		exit_shell_by_error("malloc failed");
	env = get_env(key);
	if (env == NULL)
	{
		if (ft_strlen(key) == 1 && (*key) == '?')
			return (ft_itoa(g_info.last_exit_status));
		if (ft_strlen(key) == 1 && (*key) == '$')
			return (ft_itoa(g_info.pid));
		return (ft_strdup(""));
	}
	value = ft_strdup(env->value);
	free(key);
	return (value);
}

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
