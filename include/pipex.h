/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:13:16 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/21 14:37:14 by mavellan         ###   ########.fr       */
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
# include <fcntl.h>
# include <errno.h>
# include <signal.h>

// Estrucutras
typedef struct s_pipex
{
	char	**env;
	char	**av;
	int		ac;
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

// pipex_getters.c
char	**ft_complete_paths(char **paths);
char	*ft_get_full_path(char **env);
char	**ft_get_env_paths(char **env);
char	*ft_get_cmd_path(char *cmd, char **paths);
char	*ft_get_cmd(char *cmd, t_pipex *pipex);


// pipex_ender.c
int		ft_error_msg(char *str1, char *str2, char *str3, int num_error);
void	ft_close_pipe_fd(t_pipex *pipex);
void	ft_close_fd(t_pipex *pipex);
void	ft_exit(int error_msg, t_pipex *pipex);
void	ft_free_pipex(char *str1, char *str2);

// pipex_init.c
t_pipex	pipex_init(int ac, char **av, char *env[]);
void	ft_make_pipes(t_pipex *pipex);

//pipex_open_files.c
void	ft_open_input(t_pipex *pipex);
void	ft_get_heredoc(t_pipex *pipex);
void	ft_open_output(t_pipex *pipex);


#endif
