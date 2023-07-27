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
	pid_t				pid;

	pid = fork();
	if (pid < 0)
		return (FAILURE);
	else if (pid == 0)
		get_input(hd);
	else if (pid > 0)
		if (pid_add_end(&hd->data->pid, pid) <= 0)
			return (FAILURE);
	wait_pid_list(&hd->data->pid);
	return (SUCCESS);
}

int	here_doc_main(t_data *data, t_files **inputs, t_red *red)
{
	t_hd	hd;
	char	*name;

	name = find_new_name();
	if (!name)
		return (FAILURE);
	hd.fd = open(name, O_WRONLY | O_CREAT, 0644);
	if (hd.fd < 0)
		return (FAILURE);
	hd.data = data;
	hd.limiter = red->content;
	hd.type = red->cont_type;
	hd.name = name;
	if (fork_here_doc(&hd) <= 0)
		return (FAILURE);
	close(hd.fd);
	hd.fd = open(name, O_RDONLY);
	if (file_add_end(inputs, hd.fd, name, true) <= 0)
		return (FAILURE);
	return (SUCCESS);
}
