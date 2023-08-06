/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:33:13 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/06 16:52:06 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*make_env(char *env_line)
{
	t_env	*new_env;
	int		seperator_idx;
	char	*value;

	new_env = (t_env *)malloc(sizeof(t_env));
	// = 기준으로 나눔.
	seperator_idx = ft_index_str(env_line, '=');
	new_env->key = ft_strndup(env_line, seperator_idx);
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
	// t_env	*lvl;

	env_list = NULL;
	while (*envp)
	{
		add_env(&env_list, *envp);
		envp++;
	}
	g_info.env_list = env_list;
	while (env_list)
	{
		printf("%s = %s\n\n", env_list->key, env_list->value);
		env_list = env_list->next;
	}
	// lvl = get_env("SHLVL");
	// if (lvl)
	// {
	// 	next_leve = ft_atoi(lvl->value) + 1;
	// 	free(lvl->value);
	// 	lvl->value = ft_itoa(next_leve);
	// 	if (!lvl->value)
	// 		ft_error_exit("malloc", strerror(errno), FAIL);
	// }
	// else
	// 	add_env(&head, "SHLVL=1");
	// make_env_arr();
}
