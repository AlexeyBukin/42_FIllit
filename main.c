/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:54:44 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/26 19:27:07 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"

#include <stdio.h>

extern int			g_best_perimeter;
extern t_field		g_best_field;



int		main(int argc, char **argv)
{
	t_mino	    array[26];
	int 	    i;
	int 	    fd;

	if (argc != 2)
	{
		print_usage();
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	i = -1;
	while (++i < 26)
	{
		if (!read_tmino(fd, array[i]))
			break ;
		read_newline(fd);
	}

	if (read_newline(fd))
    {
	    print_error();
	    return (0);
    }
	printf("\nnum = %d\n", i);

	start(array, i);
	//rec_puzzle(test_field, array, num);
	//rec_puzzle(test_field, array, 3);

	printf("\nbest size = %d\n", g_best_perimeter);
	print_field(g_best_field, 8);
	return (0);
}

