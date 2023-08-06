/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:08 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/06 22:35:52 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

void	init_env(char **env);
void	exit_shell(char *str);
void	exit_shell_by_error(char *str);
void    set_terminal(void);
void	set_signal(void);

#endif