/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:13:16 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/20 19:35:54 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_h

# include "../libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/wait.h>





typedef struct s_pipex
{
	char	**env;
	char	**av;
	int		argc;
	int		here_doc;
	int		fd_in;
	int		fd_out;
	int		*pipe;
	int		nb_cmds;
	int		child;
	pid_t	*pids;
	char	*cmd_options;
	char	*cmd_path;
}	t_pipex;

int		ft_error_msg(char *str1, char *str2, char *str3, int num_error);
t_pipex	pipex_init(int ac, char **av, char *env[]);

#endif
