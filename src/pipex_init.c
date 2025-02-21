/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:38:53 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/21 09:39:55 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_make_pipes(t_pipex *pipex)
{
	int i;

	i = 0;
	while (i < pipex->nb_cmds - 1)
	{
		if (pipe(pipex->pipe + 2 * i) == - 1)
			ft_exit(ft_error_msg("Couldn't create pipe", "", "", 1), pipex);
		i++;
	}
}

t_pipex	init_struct(void)
{
	t_pipex pipex;

	pipex.env = NULL;
	pipex.ac = -1;
	pipex.av = NULL;
	pipex.here_doc = 0;
	pipex.fd_in = -1;
	pipex.fd_out = -1;
	pipex.pipe = NULL;
	pipex.child = -1;
	pipex.nb_cmds = -1;
	pipex.pids = NULL;
	pipex.cmd_options = NULL;
	pipex.cmd_path = NULL;
	return (pipex);
}

t_pipex	pipex_init(int ac, char **av, char *env[])
{
	t_pipex	pipex;

	pipex = init_struct();
	pipex.env = env;
	pipex.av = av;
	pipex.ac = ac;
	if (!ft_strncmp("here_doc", av[1], 9))
		pipex.here_doc = 1;
	ft_open_input(&pipex);
	ft_open_outpu(&pipex);
	pipex.nb_cmds = ac - 3 - pipex.here_doc;
	pipex.pids = malloc(sizeof(pipex.pids) * pipex.nb_cmds);
	if (!pipex.pids)
		ft_exit(ft_error_msg("PID error", strerror(errno), "", 1), &pipex);
	pipex.pipe = malloc(sizeof(pipex.pipe) * (pipex.nb_cmds - 1) * 2);
	if (!pipex.pipe)
	ft_exit(ft_error_msg("pipe error", strerror(errno), "", 1), &pipex);
	ft_make_pipes(&pipex);
	return(pipex);
}
