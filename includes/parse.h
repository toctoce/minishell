/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:48 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/12 21:46:33 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

void	parse(t_argv **argvs);
int     input_to_line(t_parse *info);
int	    line_to_tokens(t_list **tokens, t_list **dummys, char *line);
void	create_dummies(t_list **dummy_list, char *line);

#endif