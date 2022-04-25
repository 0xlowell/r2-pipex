/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:18:04 by lzima             #+#    #+#             */
/*   Updated: 2022/04/25 16:18:05 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include <errno.h>

typedef struct s_pipe
{
	pid_t	p1;
	pid_t	p2;
	int		pipe[2];
	int		in;
	int		out;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipe;

/* utils.c */
char	**ft_split(const char *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);

/* utils_str.c */
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

/* pipex.c */
void	launcher(t_pipe pipex, char **av, char **envp);
void	second_child_process(t_pipe pipex, char *argv[], char *envp[]);
void	first_child_process(t_pipe pipex, char *argv[], char *envp[]);
void	cmd_args_free(t_pipe *pipex);

/* fonctions.c */
int		message(char *message);
void	error_message(char *message, int state);
char	*get_path(char **envp);
void	cmd_paths_free(t_pipe *pipex);
char	*get_cmd(char **paths, char *cmd);

#endif

/* ### TYPE
 * pid_t
 *
 * pid_t data type stands for process identification and it is used
 *  to represent process ids. Whenever, we want to declare a variable 
 *  that is going to be deal with the process ids we can use pid_t data type.
*/

/*
### NAME
wait, waitpid - wait for a child process to stop or terminate

### SYNOPSIS
#include <sys/wait.h>

pid_t wait(int *stat_loc);
pid_t waitpid(pid_t pid, int *stat_loc, int options);

### DESCRIPTION
The wait() and waitpid() functions shall obtain status information 
pertaining to one of the caller's child processes.
*/
