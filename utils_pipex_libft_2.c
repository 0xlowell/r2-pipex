/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils_pipex_libft_2.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lzima <marvin@42lausanne.ch>			   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/05 23:50:26 by lzima			 #+#	#+#			 */
/*   Updated: 2022/04/06 00:03:38 by lzima			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	slen1;
	size_t	slen2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	ret = malloc ((slen1 + slen2 + 1) * sizeof(char));
	if (!ret)
		return (0);
	j = 0;
	while (s1[i])
		ret[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] == s2[i])
			;
		if (!(s1[i] == s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	slen;

	if (!s)
		return (0);
	i = 0;
	slen = ft_strlen(s);
	if (slen < len)
		len = slen;
	s2 = malloc(((len + 1)) * sizeof(char));
	if (!s2 || !s)
		return (NULL);
	while (i < len && start < slen)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dtab;
	unsigned const char	*stab;

	if (dst == src)
		return (dst);
	dtab = (unsigned char *)dst;
	stab = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		dtab[i] = stab[i];
		i++;
	}
	return (dtab);
}
