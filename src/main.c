/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:05 by pconin            #+#    #+#             */
/*   Updated: 2016/04/05 16:23:36 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env	*stock;

	stock = (t_env*)malloc(sizeof(t_env));
	open_and_read(argv[1], argc, stock);
	put_in_map(stock);
	ft_setwin(stock);
	return (0);
}
