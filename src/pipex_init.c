/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:38:53 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/20 19:24:34 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex	init_struct(void)
{
	t_pipex pipex;

	pipex.env = NULL;
	pipex.argc = -1;
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
}
