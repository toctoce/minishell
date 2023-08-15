/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:26 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/15 16:19:33 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_str_double_join(char *str1, char *str2, char *str3)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(str1, str2);
	check_malloc_error(tmp);
	res = ft_strjoin(tmp, str3);
	free(tmp);
	check_malloc_error(res);
	return (res);
}

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
