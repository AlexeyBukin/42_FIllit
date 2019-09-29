/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:54:44 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/28 13:40:23 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"

int		main(int argc, char **argv)
{
	t_mino	    array[27];
	int 	    i;
	int 	    fd;
    int         num;
    int         rnl;
    int         rt;
    int         sum;
    int         j;

	if (argc != 2)
		print_usage();
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < 27 && ( rt = read_tmino(fd, array[i]) ) != 0 && ( rnl = read_newline(fd) ) != 0)
	    i++;

    printf("rnl: %d, rt: %d, i: %d\n", rnl, rt, i);

    num = i + 1;

	while (i < num)
    {
        sum = 0;
        j = 0;
	    while (j < TMINO_STR_LEN)
	        sum += array[i][j++];
	    if (sum != (('.' * 12) + ('#' * 4)))
            print_error();
	    i++;
    }

	if (rnl != 0 || rt == 0 || num > 26 || num < 1)
	    print_error();

	start(array, num);

	printf("\nbest size = %d\n", g_best_perimeter);
	print_field(g_best_field, g_best_perimeter);
	return (0);
}
