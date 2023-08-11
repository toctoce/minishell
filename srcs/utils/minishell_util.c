/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:26 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/11 18:24:28 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
