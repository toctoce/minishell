/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:42:17 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:47:14 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_export(void)
{
	t_env	*tmp;

	tmp = g_info.env_list;
	while (tmp)
	{
		printf("declare -x %s", tmp->key);
		if (tmp->value)
			printf("=\"%s\"", tmp->value);
		printf("\n");
		tmp = tmp->next;
	}
}

static void	is_update_env(char *cmd)
{
	t_env	*env;
	t_env	*exist;

	env = make_env(cmd);
	exist = get_env(env->key);
	if (exist == NULL)
	{
		free(env->key);
		free(env->value);
		free(env);
		add_env(&(g_info.env_list), cmd);
	}
	else
	{
		free(exist->value);
		exist->value = env->value;
		free(env->key);
		free(env);
	}
}

void	run_export(char **cmd)
{
	int		idx;
	char	*msg;

	idx = 1;
	if (!cmd[1])
		return (print_export());
	while (cmd[idx])
	{
		if (!is_valid_key(cmd[idx]))
		{
			msg = ft_strjoin("export: not an identifer: ", cmd[idx]);
			ft_putendl_fd(msg, 2);
			free(msg);
			g_info.last_exit_status = FAIL;
		}
		else
			is_update_env(cmd[idx]);
		idx++;
	}
	reset_envp();
}
