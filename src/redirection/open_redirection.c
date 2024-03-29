/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:20:56 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:20:57 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/redirection.h"

static int	redirection_choice(t_data *data, t_red *red, t_files *file)
{
	if (red->type == HERE_DOC || red->type == RED_IN)
		return (input_redirection_choice(data, red, file));
	else
		return (output_redirection_choice(red, file));
	return (SUCCESS);
}

static int	add_redirection(t_data *data, t_files *file, int index)
{
	t_files	**choice;

	if (file->input)
	{
		choice = &data->cmds[index].input;
	}
	else
		choice = &data->cmds[index].output;
	if (file_add_end(choice, file->fd, file->name, file->here_doc) <= 0)
		return (FAILURE);
	return (SUCCESS);
}

static int	next_red(t_data *data, int index, t_red **ptr, t_files *file)
{
	*ptr = (*ptr)->next;
	if (find_next_red(file->input, *ptr) == INVALID)
	{
		if (add_redirection(data, file, index) <= 0)
			return (FAILURE);
	}
	else
	{
		if (close(file->fd))
			return (print_error("close"), FAILURE);
		if (file->here_doc)
		{
			unlink(file->name);
			ft_free(file->name);
		}
	}
	return (SUCCESS);
}

static int	open_redirection(t_data *data, size_t index)
{
	t_red	*ptr;
	t_files	file;
	int		exit_code;

	ptr = data->cmds[index].red;
	while (ptr != NULL)
	{
		exit_code = redirection_choice(data, ptr, &file);
		if (exit_code == FAILURE)
			return (FAILURE);
		else if (exit_code == INVALID)
		{
			if (add_redirection(data, &file, index) <= 0)
				return (FAILURE);
			return (INVALID);
		}
		else
			if (next_red(data, index, &ptr, &file) <= 0)
				return (FAILURE);
	}
	return (SUCCESS);
}

int	convert_redirection(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_pipe + 1)
	{
		if (open_redirection(data, i) < 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
