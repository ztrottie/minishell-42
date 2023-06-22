/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:58:06 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/22 17:16:55 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cmds.h"

void	single_quote_control(t_lines *lines)
{
	lines->i_line++;
	while (is_quote(lines->line[lines->i_line]) != SINGLE_QUOTE)
	{
		lines->parsed_line[lines->i_parsed_line] = lines->line[lines->i_line];
		lines->i_parsed_line++;
		lines->i_line++;
	}
	lines->i_line++;
}
