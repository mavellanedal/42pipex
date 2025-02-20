/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ender.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:29:39 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/20 19:25:54 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_error_msg(char *str1, char *str2, char *str3, int num_error)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	return (num_error);
}

void	ft_close_pipe_fd(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->nb_cmds - 1) * 2)
	{
		close(pipex->pipe[i]);
		i++;
	}
}

void	ft_close_fd(t_pipex *pipex)
{
	if (pipex->fd_in != -1)
		close(pipex->fd_in);
	if (pipex->fd_out != -1)
		close(pipex->fd_out);
	ft_close_pipe_fd(pipex);
}

void	ft_exit(int error_msg, t_pipex *pipex)
{
	if (pipex)
	{
		ft_close_fd(pipex);
		if (pipex->pipe)
			free(pipex->pipe);
		if (pipex->pids)
			free(pipex->pids);
		if (pipex->cmd_options || pipex->cmd_path)
			ft_free_pipex(pipex->cmd_path, pipex->cmd_options);
	}
}

void	ft_free_pipex(char *str1, char *str2)
{
	int	i;

	if (str1 != NULL)
	{
		free(str1);
		str1 = NULL;
	}
	i = 0;
	if (str2 != NULL)
	{
		while (str2[i])
		{
			free(str2[i]);
			i++;
		}
		free(str2);
		str2 = NULL;
	}
}
