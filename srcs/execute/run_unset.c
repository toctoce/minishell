#include "../../includes/execute.h"

static void	del_env_one(t_env *del)
{
	if (del->prev)
		del->prev->next = del->next;
	else
		g_info.env_list = del->next;
	if (del->next)
		del->next->prev = del->prev;
	free(del->key);
	free(del->value);
	free(del);
}

void	run_unset(char **cmd)
{
	t_env	*del;
	int		idx;

	idx = 1;
	if (!cmd[1])
		return ;
	while (cmd[idx])
	{
		del = get_env(cmd[idx]);
		if (del)
			del_env_one(del);
        idx++;
	}
}
