#include "../../include/parsing.h"

static int	env_varaible_control(t_data *data, t_line *line, t_line *content)
{
	char 	*name;
	char 	*var_content;
	size_t	i;

	name = variable_name(line->line + line->i_line);
	if (!name)
		return (INVALID);
	var_content = env_variable(data, name);
	if (var_content)
	{
		i = 0;
		while (var_content[i])
		{
			content->line[content->i_line] = var_content[i];
			i++;
			content->i_line++;
		}
	}
	line->i_line += ft_strlen(name);
	return (ft_free(name), SUCCESS);
}

static int	exit_variable_control(t_data *data, t_line *line, t_line *content)
{
	char	*exit_code;
	size_t	i;

	exit_code = ft_itoa(data->exit_code);
	if (!exit_code)
		return (FAILURE);
	i = 0;
	while (exit_code[i])
	{
		content->line[content->i_line] = exit_code[i];
		content->i_line++;
		i++;
	}
	line->i_line++;
	return (SUCCESS);
}

int	variable_control(t_data *data, t_line *line, t_line *content, int quote)
{
	if (line->line[line->i_line + 1] && line->line[line->i_line + 1] != ' ' && (quote && is_quote(line->line[line->i_line + 1]) != quote))
		line->i_line++;
	else
		return (basic_control(line, content), SUCCESS);
	if (line->line[line->i_line] == '?')
		exit_variable_control(data, line, content);
	else
		env_varaible_control(data, line, content);
	return (SUCCESS);
}
