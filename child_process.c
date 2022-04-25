/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:12:51 by lzima             #+#    #+#             */
/*   Updated: 2022/04/25 16:12:54 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* Your objective is to code the Pipex program.
 * It should be executed in this way:
 *
 * $> ./pipex file1 cmd1 cmd2 file2
 *
 * Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands
 * with their parameters. The execution of the pipex program should do the same
 * as the next shell command:
 *
 * $> < file1 cmd1 | cmd2 > file2
 * example :
 *
 * $> ./pipex infile "ls" "wc" outfile
 *
 * need to be equal to :
 *
 * < file1 ls | wc > file2
*/

void	cmd_args_free(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
		free(pipex->cmd_args[i++]);
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	first_child_process(t_pipe pipex, char **av, char **envp)
{
	close(pipex.pipe[0]);
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[1]);
	dup2(pipex.in, 0);
	close(pipex.in);
	pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	fprintf(stderr, "pipex.cmd1= %s\n", pipex.cmd);
	if (!pipex.cmd)
	{
		cmd_args_free(&pipex);
		message("Command not found\n");
		cmd_paths_free(&pipex);
		exit(127);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	cmd_paths_free(&pipex);
	perror(strerror(errno));
	exit(1);
}

void	second_child_process(t_pipe pipex, char **av, char **envp)
{
	close(pipex.pipe[1]);
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[0]);
	dup2(pipex.out, 1);
	close(pipex.out);
	pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	fprintf(stderr, "pipex.cmd1= %s\n", pipex.cmd);
	if (!pipex.cmd)
	{
		cmd_args_free(&pipex);
		message("Command not found\n");
		cmd_paths_free(&pipex);
		exit(127);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	cmd_paths_free(&pipex);
	perror(strerror(errno));
	exit(1);
}

void	launcher(t_pipe pipex, char **av, char **envp)
{
	pipex.p1 = fork();
	if (pipex.p1 == 0)
		first_child_process(pipex, av, envp);
	pipex.p2 = fork();
	if (pipex.p2 == 0)
		second_child_process(pipex, av, envp);
}
