#include "../../include/here_doc.h"

static char	*find_new_name(void)
{
	int		i;
	char	*base_path;
	char	*nb;
	char	*name;

	base_path = "/tmp/.here_doc";
	i = 0;
	while (i < 100)
	{
		nb = ft_itoa(i);
		if (!nb)
			return (NULL);
		name = ft_strjoin(base_path, nb);
		if (!name)
			return (ft_free(nb), NULL);
		if (access(name, F_OK) == -1)
			return (ft_free(nb), name);
		ft_free(nb);
		ft_free(name);
		i++;
	}
	return (ft_free(name), ft_free(nb), NULL);
}

int	fork_here_doc(t_data *data, int fd, char *limiter, int type)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (FAILURE);
	else if (pid == 0)
		get_input(fd, limiter, type);
	else
		if (pid_add_end(data, pid) <= 0)
			return (FAILURE);
	return (SUCCESS);
}

int	here_doc_main(t_data *data, t_files **inputs, char *limiter, int type)
{
	char	*name;
	int		fd;

	name = find_new_name();
	if (!name)
		return (FAILURE);
	fd = open(name, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		return (FAILURE);
	if (fork_here_doc(data, fd, limiter, type) <= 0)
		return (FAILURE);
	close(fd);
	fd = open(name, O_RDONLY);
	if (file_add_end(inputs, name, fd) <= 0)
		return (FAILURE);
	return (SUCCESS);
}
