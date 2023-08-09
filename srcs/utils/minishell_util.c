#include "../../includes/minishell.h"

int	all_isspace(char *line)
{
	while (*line)
	{
		if (ft_isspace(*line) == FALSE)
			return (FALSE);
		line++;
	}
	return (TRUE);
}
