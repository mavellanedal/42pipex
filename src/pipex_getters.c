/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:19:51 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/21 14:35:54 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**ft_complete_paths(char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		ft_free_pipex(tmp, NULL);
		i++;
	}
	return (paths);
}

char	*ft_get_full_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while(env[i] && env[1][0] != '\0')
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path));
			break;
		}
		i++;
	}
	return (path);
}

char	**ft_get_env_paths(char **env)
{
	char	*env_paths;
	char	**paths;

	env_paths = ft_get_full_path(env); // to do
	if (!env_paths)
		return (NULL);
	paths = ft_split(env_paths, ':');
	ft_free_pipex(env_paths, NULL);
	if (!paths)
		return (NULL);
	paths = ft_complete_paths(paths); // to do
	if (!paths)
		return (NULL);
	return (paths);
}

char	*ft_get_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;

	cmd_path = NULL;
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
		{
			ft_free_pipex(NULL, paths);
			ft_exit(ft_error_msg("Unexpected error", "", "", 1), NULL);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		ft_free_pipex(cmd_path, NULL);
		i++;
	}
	return (NULL);
}

char	*ft_get_cmd(char *cmd, t_pipex *pipex)
{
	char	**paths;
	char	**cmd_path;

	if (access(cmd, F_OK | X_OK ) == 0)
		retunr (ft_strdup(cmd));
	paths = ft_get_env_paths(pipex->env);
	if (!paths)
		return (NULL);
	cmd_path = ft_get_cmd_path(cmd, paths);
	if (!cmd_path)
		ft_error_msg("command not found", ": ", \
			pipex->av[pipex->child + 2], 1);
		ft_free_pipex(NULL, paths);
		return (cmd_path);
}
