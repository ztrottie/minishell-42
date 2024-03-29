/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:17:27 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

# include "minishell.h"
# include "commands.h"
# include "env.h"
# include "parsing.h"
# include "signal.h"

typedef struct s_hd
{
	t_data		*data;
	int			fd;
	char		*limiter;
	int			type;
	char		*name;
}	t_hd;

int		here_doc_main(t_data *data, t_red *red, char **name, bool error);
int		get_input(t_hd *hd);
size_t	parsed_line_len(t_data *data, t_lines *lines, int type);
int		hd_line_control(t_data *data, t_lines *lines, int type);
int		hd_variable_control(t_data *data, t_lines *lines);
void	hd_basic_control(t_lines *lines);

#endif