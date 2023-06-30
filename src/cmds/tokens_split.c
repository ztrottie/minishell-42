#include "../../include/cmds.h"

int	redirection_type(char *token)
{
	if (ft_strncmp(token, "<<", 3) == 0)
		return (HERE_DOC);
	if (ft_strncmp(token, ">>", 3) == 0)
		return (RED_OUT_APPEND);
	if (ft_strncmp(token, "<", 2) == 0)
		return (RED_IN);
	if (ft_strncmp(token, ">", 2) == 0)
		return (RED_OUT);
	if (ft_strncmp(token, "|", 2) == 0)
		return (PIPE);
	return (0);
}

void	fill_tokens(t_tokens *tokens, char **tokens_split)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tokens_split[i])
	{
		tokens[j].content = tokens_split[i];
		tokens[j].type = redirection_type(tokens_split[i]);
		j++;
		i++;
	}
	ft_free(tokens_split);
}

int	init_tokens(t_tokens **tokens, char *parsed_line, char ***tokens_split)
{
	size_t	token_nb;

	token_nb = ft_word_count(parsed_line, 29);
	*tokens = ft_calloc(token_nb + 1, sizeof(t_tokens));
	if (!*tokens)
		return (ft_free(parsed_line), FAILURE);
	*tokens_split = ft_split(parsed_line, 29);
	if (!*tokens_split)
		return (ft_free(parsed_line), ft_free(*tokens), FAILURE);
	return (ft_free(parsed_line), SUCCESS);
}

int	tokens_parsing(t_data *data, char *parsed_line)
{
	t_tokens 	*tokens;
	char		**tokens_split;

	(void)data;
	if (!init_tokens(&tokens, parsed_line, &tokens_split))
		return (FAILURE);
	fill_tokens(tokens, tokens_split);
	for (int i = 0; tokens[i].content; i++)
		ft_printf("[%d]|%s|\n", tokens[i].type, tokens[i].content);
	return (SUCCESS);
}
