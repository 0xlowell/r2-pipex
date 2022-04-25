/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:18:50 by lzima             #+#    #+#             */
/*   Updated: 2022/04/25 16:18:52 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	message(char *message)
{
	write(2, message, ft_strlen(message));
	return (1);
}

void	error_message(char *message, int state)
{
	if (!state)
		return ;
	perror(message);
	exit(1);
}

void	cmd_paths_free(t_pipe *pipex)
{
	int	i;

	close(pipex->in);
	close(pipex->out);
	i = 0;
	while (pipex->cmd_paths[i])
		free(pipex->cmd_paths[i++]);
	free(pipex->cmd_paths);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

char	*get_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	return (*envp + 5);
}
