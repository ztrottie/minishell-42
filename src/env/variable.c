/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:32 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:19:33 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/env.h"

size_t	variable_name_len(char *line)
{
	size_t	i;

	i = 0;
	while (is_valid_var(line[i]) == VALID)
		i++;
	return (i);
}

char	*variable_name(char *line)
{
	size_t	i;
	size_t	len;
	char	*name;

	len = variable_name_len(line);
	if (!len)
		return (NULL);
	name = ft_calloc(len + 1, sizeof(char));
	if (!name)
		return (print_error("malloc"), NULL);
	i = 0;
	while (i < len)
	{
		name[i] = line[i];
		i++;
	}
	return (name);
}

size_t	variable_content_len(t_data *data, char *line_read)
{
	size_t	i;
	size_t	len;
	char	*var_name;

	i = 0;
	len = 0;
	var_name = NULL;
	while (line_read[i])
	{
		if (line_read[i] == '$')
		{
			var_name = variable_name(line_read + i + 1);
			len += ft_strlen(env_variable(data, var_name));
		}
		i++;
	}
	return (ft_free(var_name), len);
}

char	*env_variable(t_data *data, char *name)
{
	size_t	i;
	char	*variable;
	char	*var_content;

	if (!data->env)
		return (NULL);
	variable = ft_strjoin(name, "=");
	if (!variable)
		return (NULL);
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], variable, ft_strlen(variable)) == 0)
		{
			var_content = ft_strdup(data->env[i] + ft_strlen(variable));
			return (ft_free(variable), var_content);
		}
		i++;
	}
	return (ft_free(variable), NULL);
}
