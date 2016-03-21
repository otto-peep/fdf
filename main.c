/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:05 by pconin            #+#    #+#             */
/*   Updated: 2016/03/19 18:18:34 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	s_env	*stock;

	stock = (s_env*) malloc (sizeof(s_env));
	open_and_read(argv[1], argc, stock);
	put_in_map(stock);
	ft_setwin(stock);
	ft_puttabnbr(stock->map, stock->len, stock->width);
	return (0);
}
