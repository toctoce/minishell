#include "../../includes/execute.h"

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

static int	is_update_env(char *cmd)
{
	t_env	*exist;
	char	*key;
	char	*value;

	key = make_key(cmd);
	exist = get_env(key);
	if (!exist)
	{
		free(key);
		return (FALSE);
	}
	free(key);
	value = ft_strchr(cmd, '=');
	if (!value)
		return (TRUE);
	free(exist->value);
	exist->value = ft_strdup(++value);
	if (!exist->value)
		exit_shell_by_error("malloc failed");
	return (TRUE);
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
		else if (!is_update_env(cmd[idx]))
			add_env(&g_info.env_list, cmd[idx]);
		idx++;
	}
}
