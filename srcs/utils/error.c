/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:51:31 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/06 14:53:36 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_shell(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	exit_shell_by_error(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}
