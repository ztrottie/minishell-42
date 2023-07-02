#include "../../include/cmds.h"

int	is_token_quote(char *token)
{
	if (ft_strlen(token) > 1)
		return (0);
	return (is_quote(token[0]));
}

int	redirection_type(char *token, int flag)
{
	if (flag)
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
	}
	return (0);
}

int fill_tokens(t_tokens **tokens, char **tokens_split)
{
    size_t i;
    int quote;
    int type;
	int	flag;

    i = 0;
	flag = -1;
    while (tokens_split[i])
    {
        quote = is_token_quote(tokens_split[i]);
		if (quote)
			flag *= -1;
        type = redirection_type(tokens_split[i], flag);
        if (!token_add_end(tokens, type, tokens_split[i]))
			return (FAILURE);
        i++;
    }
	return (SUCCESS);
}


int	init_tokens(char *parsed_line, char ***tokens_split)
{
	*tokens_split = ft_split(parsed_line, 29);
	if (!*tokens_split)
		return (ft_free(parsed_line), FAILURE);
	return (ft_free(parsed_line), SUCCESS);
}

int tokens_parsing(t_data *data, char *parsed_line)
{
    t_tokens *tokens;
    char **tokens_split;

    (void)data;
    tokens = NULL;
    if (!init_tokens(parsed_line, &tokens_split))
        return (FAILURE);
    fill_tokens(&tokens, tokens_split);
    while (tokens != NULL)
	{
        ft_printf("[%d]|%s|\n", tokens->type, tokens->content);
		tokens = tokens->next;
	}
    return (SUCCESS);
}