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

static int	fork_here_doc(t_hd *hd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return (print_error("fork"), FAILURE);
	else if (pid == 0)
		get_input(hd);
	else if (pid > 0)
		waitpid(pid, &status, 0);
	return (SUCCESS);
}
static int	init_hd(t_data *data, t_hd *hd, t_red *red)
{
	hd->data = data;
	hd->limiter = red->content;
	hd->type = red->cont_type;
	hd->name = find_new_name();
	if (!hd->name)
		return (FAILURE);
	hd->fd = open(hd->name, O_WRONLY | O_CREAT, 0644);
	if (hd->fd < 0)
		return (FAILURE);
	return (SUCCESS);
}

static int	hd_error_handler(t_data *data, t_hd *hd)
{
	struct stat	tmp_info;

	if (access(hd->name, F_OK) == 0)
	{
		if (stat(hd->name, &tmp_info) < 0)
			return (FAILURE);
		if (tmp_info.st_mtimespec.tv_sec != data->info_last_hd.st_mtimespec.tv_sec \
		|| tmp_info.st_mtimespec.tv_nsec != data->info_last_hd.st_mtimespec.tv_nsec)
			return (errno = ENOENT, INVALID);
		else
			if (unlink(hd->name) < 0)
				return (FAILURE);
	}
	else
		return (errno = ENOENT, INVALID);
	return (SUCCESS);
}

int	here_doc_main(t_data *data, t_red *red, char **name, bool error)
{
	t_hd	hd;

	if (init_hd(data, &hd, red) <= 0)
		return (FAILURE);
	if (fork_here_doc(&hd) <= 0)
		return (FAILURE);
	if (fstat(hd.fd, &data->info_last_hd) < 0)
		return (perror("fstat"), FAILURE);
	if (close(hd.fd) < 0)
		return (print_error("close"), FAILURE);
	if (error)
		return (hd_error_handler(data, &hd));
	else
		*name = hd.name;
	return (SUCCESS);
}
