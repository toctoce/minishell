/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:19:51 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/15 18:05:14 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "struct.h"
# include "util.h"
# include "parse.h"
# include "execute.h"

void print(char *str);

extern t_info	g_info;

#endif