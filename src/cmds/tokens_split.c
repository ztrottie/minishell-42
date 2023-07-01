#include "../../include/cmds.h"

int	is_token_quote(char *token)
{
	if (ft_strlen(token) > 1)
		return (0);
	return (is_quote(token[0]));
}

int	redirection_type(char **token_split, size_t index)
{
	if (index > 0 && !is_token_quote(token_split[index - 1]))
	{
		if (ft_strncmp(token_split[index], "<<", 3) == 0)
			return (HERE_DOC);
		if (ft_strncmp(token_split[index], ">>", 3) == 0)
			return (RED_OUT_APPEND);
		if (ft_strncmp(token_split[index], "<", 2) == 0)
			return (RED_IN);
		if (ft_strncmp(token_split[index], ">", 2) == 0)
			return (RED_OUT);
		if (ft_strncmp(token_split[index], "|", 2) == 0)
			return (PIPE);
	}
	return (0);
}

void	fill_tokens(t_tokens **tokens, char **tokens_split)
{
	size_t	i;
	int 	quote;
	int		type;

	i = 0;
	while (tokens_split[i])
	{
		quote = is_token_quote(tokens_split[i]);
		if (!quote)
		{
			type = redirection_type(tokens_split, i);
			token_add_end(*tokens, type, tokens_split[i]);
		}
		i++;
	}
}

int	init_tokens(char *parsed_line, char ***tokens_split)
{
	*tokens_split = ft_split(parsed_line, 29);
	if (!*tokens_split)
		return (ft_free(parsed_line), FAILURE);
	return (ft_free(parsed_line), SUCCESS);
}

int	tokens_parsing(t_data *data, char *parsed_line)
{
	t_tokens 	*tokens;
	char		**tokens_split;

	(void)data;
	if (!init_tokens(parsed_line, &tokens_split))
		return (FAILURE);
	fill_tokens(&tokens, tokens_split);
	return (SUCCESS);
}
