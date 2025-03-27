/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:33:02 by mavellan          #+#    #+#             */
/*   Updated: 2025/03/27 12:37:32 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*If there is a here_doc in the program executation, the program will get it,
then we will open a temporal file for the here_doc.
If there isn't here_doc the program only open the file in the first position
of the argv.
Bouth of them are opened with read only permissions. */
void	ft_open_input(t_pipex *pipex)
{
	if (pipex->here_doc == 1)
	{
		ft_get_heredoc(pipex);
		pipex->fd_in = open(".heredoc.tmp", O_RDONLY);
		if (pipex->fd_in == -1)
			ft_exit(ft_error_msg("here_doc", ":", strerror(errno), 1), pipex);
	}
	else
	{
		pipex->fd_in = open(pipex->av[1], O_RDONLY, 644);
		if (pipex->fd_in == -1)
			ft_error_msg(strerror(errno), ": ", pipex->av[1], 1);
	}
}

/*If there is a here_doc in the program executation, it will create open de out_file
with the parameters O_APPEND para agregar conteindo al final del archuivo, en caso de no haber here_doc
el contenido se borra completamente.
If there isn't here_doc the program only open the file in the first position
of the argv.
Bouth of them are opened with read only permissions. */

void	ft_open_output(t_pipex *pipex)
{
	if (pipex->here_doc == 1)
		pipex->fd_out = open(pipex->av[pipex->ac - 1], \
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->fd_out = open(pipex->av[pipex->ac -1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out == -1)
		ft_error_msg(strerror(errno), ": ", pipex->av[pipex->ac - 1], 1);
}

/*It reed the inputs of the terminal while the intpus is not the LIMITER.
Save the lines in .heredoc.tmp*/
void	ft_get_heredoc(t_pipex *pipex)
{
	int		tmp_fd;
	int		stdin_fd;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	stdin_fd = dup(STDIN_FILENO);
	if (tmp_fd == -1)
		ft_exit(ft_error_msg("here_doc", ": ", strerror(errno), 1), pipex);
	line = "";
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(stdin_fd);
		if (line == NULL)
			break ;
		if (ft_strlen(pipex->av[2]) + 1 == ft_strlen(line) \
			&& !ft_strncmp(line, pipex->av[2], ft_strlen(pipex->av[2] + 1)))
			close (stdin_fd);
		else
			ft_putstr_fd(line, tmp_fd);
		free(line);
	}
	close (tmp_fd);
}
