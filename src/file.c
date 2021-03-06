/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:07 by pconin            #+#    #+#             */
/*   Updated: 2016/09/15 15:14:32 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_readnly(int fd, char **dst, size_t size)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*tmp;

	*dst = (char *)malloc(sizeof(char) * 1);
	ft_bzero(*dst, 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(*dst, buf);
		free(*dst);
		*dst = tmp;
	}
	if (ret < 0)
		ft_error("error during read");
	size = size - 1;
}

int			ft_open_rdly(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("error during open");
	return (fd);
}

void		open_and_read(char *file, int argc, t_env *stock)
{
	int		fd;

	if (argc != 2)
		ft_error("wrong number of argument\n");
	fd = ft_open_rdly(file);
	ft_readnly(fd, &(stock->file), BUFF_SIZE);
}
