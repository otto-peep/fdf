/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:27:59 by pconin            #+#    #+#             */
/*   Updated: 2016/02/03 19:14:09 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>

size_t		found_newline(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	return (i);
}

size_t		newline(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_read(int fd, char **tmp, int *ret)
{
	char *buf;
	char *mem;

	mem = NULL;
	buf = NULL;
	buf = ft_strnew(BUFF_SIZE + 1);
	*ret = read(fd, buf, BUFF_SIZE);
	if (*ret == -1)
		return ;
	mem = *tmp;
	*tmp = ft_strjoin(*tmp, buf);
	free(mem);
	free(buf);
	return ;
}

int		get_next_line(int const fd, char **line)
{
	static char *tmp;
	int			ret;
	char		*mem;

	ret = 1;
	mem = NULL;
	if (tmp == NULL)
		tmp = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || line == NULL)
		return (-1);
	while (ret > 0 && newline(tmp) == 0 && tmp != NULL)
	{
		ft_read(fd, &tmp, &ret);
		if (found_newline(tmp) != ft_strlen(tmp) || ret == -1)
			break ;
	}
	if (ret == -1 || tmp == NULL)
		return (-1);
	*line = ft_strsub(tmp, 0, found_newline(tmp));
	if (!(ft_strlen(tmp)) && ret == 0)
		return (0);
	mem = tmp;
	tmp = ft_strsub(tmp, found_newline(tmp) + 1, ft_strlen(tmp));
	free(mem);
	return (1);
}
