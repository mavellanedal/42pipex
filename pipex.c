/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:27 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/13 08:43:28 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int ac, char **av, char *env[])
{
	t_pipex	pipex;
	int		exit_code;
	if (ac < 5)
	{
		if (ac >= 2 && !ft_strncmp("here_doc", av[1], 9))
			return (ft_error_msg("Usage: ",
			"./pipex here_doce LIMITER cmd1 cmd2 ... cmdn file2", "", 1));
		return (ft_error_msg("Usage: ",
		"./pipex file1 cmd1 cmd2 ... cmdn file2", "", 1));
	}
	else if (ac < 6 && !ft_strncmp("here_doc", av[1], 9))
		return (ft_error_msg("Usage: ",
		"./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2", "", 1));
	if (!env || env[0][0] == '\0')

	pipex = px_init(ac, av, env);
}
