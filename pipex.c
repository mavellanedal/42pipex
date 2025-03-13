/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:27 by mavellan          #+#    #+#             */
/*   Updated: 2025/03/13 19:44:13 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

/*It compares if the program have 2 or more arguments and there
is no here_doc added.
If it have heredoce, it must have at least 6  arguments.
Also check if ther is no env.*/

int	main(int ac, char **av, char *env[])
{
	t_pipex	pipex;
	int		exit_code;

	if (ac < 5)
	{
		if (ac >= 2 && !ft_strncmp("here_doc", av[1], 9))
			return (ft_error_msg("Usage: ", \
			"./pipex here_doce LIMITER cmd1 cmd2 ... cmdn file2", "", 1));
		return (ft_error_msg("Usage: ", \
		"./pipex file1 cmd1 cmd2 ... cmdn file2", "", 1));
	}
	else if (ac < 6 && !ft_strncmp("here_doc", av[1], 9))
		return (ft_error_msg("Usage: ", \
		"./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2", "", 1));
	if (!env || env[0][0] == '\0')
		ft_exit(ft_error_msg("Unexpected error.", "", "", 1), &pipex);
	pipex = pipex_init(ac, av, env);
	exit_code = ft_run_pipex(&pipex);
	return (exit_code);
}
