/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:31:01 by pconin            #+#    #+#             */
/*   Updated: 2016/03/15 17:12:03 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

void	ft_newline(s_points *line, char *temp)
{
	s_points *new;
	char **tab;
	int		a;
	
	a = 0;
	tab = ft_strsplit(temp, ' ');
	while(temp[a])
		a++;
	new->x = malloc(sizeof (int) * (a + 1));
	while (temp)
	{
		new->x[a] = ft_atoi(temp);
		a++;
		temp++;
	}
	new->x[a] = '\0';
	new->size_line = a;
	while (line->next != NULL)
		line = line->next;
	line->next = new;
	new->next = NULL;
}

s_points	*file_treat(char *file)
{
	s_points **line;
	s_points *first;
	int		fd;
	char *temp;
	int		ret;

	first = *line;
	temp = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("open error");
	while (ret == get_next_line(fd, &temp) > 0)
	{
		ft_newline(*line, temp);
		free(temp);
		temp = NULL;
	}
	if (ret == -1)
		ft_error("gnl error");
	if (close(fd) == -1)
		ft_error("error during close");
	return (line);
}
