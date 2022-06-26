/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan </var/mail/hnakatan>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:07:11 by hnakatan          #+#    #+#             */
/*   Updated: 2022/06/24 02:07:13 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s[res] != '\0')
		res ++;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i ++;
	}
	return (NULL);
}

char	*ft_strjoin(char	*s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		s1 = ft_calloc(1, sizeof(char));
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL || s1 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_cast;
	size_t			i;

	s_cast = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_cast[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
