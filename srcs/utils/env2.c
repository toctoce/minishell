/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:50:13 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:58:26 by dohyunki         ###   ########.fr       */
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
			value = ft_itoa(g_info.last_exit_status);
		else if (ft_strlen(key) == 1 && (*key) == '$')
			value = ft_itoa(g_info.pid);
		else
			value = ft_strdup("");
	}
	else
		value = ft_strdup(env->value);
	free(key);
	return (value);
}

int	get_env_key_len(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$' || str[i] == '?')
		return (1);
	if (ft_isdigit(str[i]))
		return (0);
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	return (i);
}
