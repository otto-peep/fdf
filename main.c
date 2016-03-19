/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:05 by pconin            #+#    #+#             */
/*   Updated: 2016/03/19 17:43:39 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	s_env	*stock;

	stock = (s_env*) malloc (sizeof(s_env));
	open_and_init(argv[1], argc, stock);
	ft_putstr(stock->file);
	put_in_map(stock);
	return (0);
}
	
