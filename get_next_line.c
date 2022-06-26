/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan </var/mail/hnakatan>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:06:50 by hnakatan          #+#    #+#             */
/*   Updated: 2022/06/24 02:06:51 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// int BUFFER_SIZE = 10;
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_prev_save(char *save)
{
	char	*res;
	size_t	i;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	res = (char *)malloc((i + (save[i] == '\n') + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		res[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_save(char *save)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0' || save[i + 1] == '\0')
	{
		free(save);
		return (NULL);
	}
	res = (char *)malloc((ft_strlen(save) - i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i++;
	j = i;
	while (save[i] != '\0')
	{
		res[i - j] = save[i];
		i++;
	}
	res[i - j] = '\0';
	free(save);
	return (res);
}

char	*get_now_save(char *save, int fd)
{
	char	*now;
	ssize_t	read_size;

	now = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (now == NULL)
		return (NULL);
	while (ft_strchr(save, '\n') == NULL)
	{
		read_size = read(fd, now, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(now);
			return (NULL);
		}
		if (read_size == 0)
			break ;
		now[read_size] = '\0';
		save = ft_strjoin(save, now);
		if (save == NULL)
			break ;
	}
	free(now);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = get_now_save(save, fd);
	if (save == NULL)
		return (NULL);
	res = get_prev_save(save);
	save = get_next_save(save);
	return (res);
}

// int main()
// {
// 	char *line = "";
// 	int fd = open("/mnt/c/Users/nhaya/42Tokyo/get_next_line/test.txt",O_RDONLY);
// 	int i = 0;
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL) printf("null\n");
// 		else printf("%s",line);
// 		i++;
// 	}
// 	free(line);
// 	printf("%d\n",i);
// 	// while(1);
// }