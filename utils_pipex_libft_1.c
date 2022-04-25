/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils_pipex_libft_1.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lzima <marvin@42lausanne.ch>			   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/05 23:49:49 by lzima			 #+#	#+#			 */
/*   Updated: 2022/04/06 00:03:25 by lzima			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*oneword(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	char	**splitwords;

	if (!s)
		return (0);
	splitwords = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!splitwords)
		return (0);
	i = -1;
	j = 0;
	start = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			splitwords[j++] = oneword(s, start, i);
			start = -1;
		}
	}
	splitwords[j] = 0;
	return (splitwords);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, (ft_strlen(s1) + 1));
	return (s2);
}
