/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_runner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:41:10 by mavellan          #+#    #+#             */
/*   Updated: 2025/03/27 12:43:45 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*Redirect the files input and output to the stdin and stdout*/
void	ft_redir(int input, int output, t_pipex *pipex)
{
	if (dup2(input, STDIN_FILENO) == -1)
		ft_exit(1, pipex);
	if (dup2(output, STDOUT_FILENO) == -1)
		ft_exit(1, pipex);
}

/*Whait while the child process ends and then return the exit code of the last
childprocess*/
int	ft_ex_parent(t_pipex *pipex)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	ft_close_fd(pipex);
	pipex->child--;
	exit_code = 1;
	while (pipex->child >= 0)
	{
		wpid = waitpid(pipex->pids[pipex->child], &status, 0);
		if (wpid == pipex->pids[pipex->nb_cmds - 1])
		{
			if ((pipex->child == (pipex->nb_cmds - 1)) && WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		pipex->child--;
	}
	free(pipex->pipe);
	free(pipex->pids);
	return (exit_code);
}

/*Redirect the the input and outpu, then close the files and execute execve.*/
void	ft_ex_child(t_pipex *pipex)
{
	if (pipex->child == 0)
		ft_redir(pipex->fd_in, pipex->pipe[1], pipex);
	else if (pipex->child == pipex->nb_cmds - 1)
		ft_redir(pipex->pipe[2 * pipex->child - 2], pipex->fd_out, pipex);
	else
		ft_redir(pipex->pipe[2 * pipex->child - 2], \
		pipex->pipe[2 * pipex->child + 1], pipex);
	ft_close_fd(pipex);
	if (pipex->cmd_options == NULL || pipex->cmd_path == NULL)
		ft_exit(1, pipex);
	if (execve(pipex->cmd_path, pipex->cmd_options, pipex->env) == -1)
		ft_exit(ft_error_msg(pipex->cmd_options[0], ": ", \
		strerror(errno), 1), pipex);
}

/*Create a initial pipe. For each comand divides the arguments with split,
then finde the path of the comand, create a child process and it executate the
child process. In the parent process, whait while the child process ends and if
heredoc exist, delete the .heredoc.tmp*/
int	ft_run_pipex(t_pipex *pipex)
{
	int	exit_code;

	if (pipe(pipex->pipe) == -1)
		ft_exit(ft_error_msg("pipe", ": ", strerror(errno), 1), pipex);
	pipex->child = 0;
	while (pipex->child < pipex->nb_cmds)
	{
		pipex->cmd_options = ft_split(pipex->av[pipex->child \
			+ 2 + pipex->here_doc], ' ');
		if (!pipex->cmd_options)
			ft_exit(ft_error_msg("Unexpected error", "", "", 1), pipex);
		pipex->cmd_path = ft_get_cmd(pipex->cmd_options[0], pipex);
		pipex->pids[pipex->child] = fork();
		if (pipex->pids[pipex->child] == -1)
			ft_exit(ft_error_msg("fork", ": ", strerror(errno), 1), pipex);
		else if (pipex->pids[pipex->child] == 0)
			ft_ex_child(pipex);
		ft_free_pipex(pipex->cmd_path, pipex->cmd_options);
		pipex->child++;
	}
	exit_code = ft_ex_parent(pipex);
	if (pipex->here_doc == 1)
		unlink(".heredoc.tmp");
	return (exit_code);
}
