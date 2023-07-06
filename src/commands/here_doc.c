#include "../../include/commands.h"

static char	*find_new_name(void)
{
	int		i;
	char	*base_path;
	char	*nb;
	char	*name;

	base_path = "/tmp/.here_doc";
	i = 0;
	while (i < 1)
	{
		nb = ft_itoa(i);
		if (!nb)
			return (NULL);
		name = ft_strjoin(base_path, nb);
		if (!name)
			return (NULL);
		if (access(name, F_OK) == -1)
			return (name);
		i++;
	}
	return (NULL);
}

int	get_input(int fd, char *limiter, int type)
{
	char	*line;
	char	*new_limiter;
	size_t	len;

	(void)type;
	new_limiter = ft_strjoin(limiter, "\n");
	if (!new_limiter)
		return (FAILURE);
	line = ft_strjoin(readline("> "), "\n");
	len = ft_strlen(new_limiter);
	while (line && ft_strncmp(line, new_limiter, len) != 0)
	{
		write(fd, line, sizeof(char *));
		line = ft_strjoin(readline("> "), "\n");
	}
	exit(0);
}

int	here_doc_main(t_data *data, t_files **inputs, char *limiter, int type)
{
	char	*name;
	int		fd;
	pid_t	pid;

	(void)inputs;
	name = find_new_name();
	if (!name)
		return (FAILURE);
	fd = open(name, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (FAILURE);
	pid = fork();
	if (pid < 0)
		return (FAILURE);
	else if (pid == 0)
		get_input(fd, limiter, type);
	if (pid)
		if (pid_add_end(data, pid) <= 0)
			return (FAILURE);
	return (SUCCESS);
}
