/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_runner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:41:10 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/21 09:48:26 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_run_pipex(t_pipex *pipex)
{
	int	exit_code;

	if (pipe(pipex->pipe) == -1)
		ft_exit(ft_error_msg("pipe", ": ", strerror(errno), 1), pipex);
	pipex->child = 0;
}
