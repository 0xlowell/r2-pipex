/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:16:56 by lzima             #+#    #+#             */
/*   Updated: 2022/04/25 16:17:19 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;

	if (ac != 5)
		return (message("Invalid number of arguments\n"));
	pipex.in = open(av[1], O_RDONLY);
	pipex.out = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	error_message(av[1], (int)(pipex.in < 0));
	error_message(av[4], (int)(pipex.out < 0));
	error_message("Pipe", (int)(pipe(pipex.pipe) < 0));
	pipex.paths = get_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	launcher(pipex, av, envp);
	waitpid(pipex.p1, NULL, 0);
	waitpid(pipex.p2, NULL, 0);
	cmd_paths_free(&pipex);
	return (0);
}
