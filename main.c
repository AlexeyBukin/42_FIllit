/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:54:44 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/01 18:32:52 by kcharla          ###   ########.fr       */
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
	while (i < 27 && ( rt = read_tmino(fd, array[i]) ) > 0 && ( rnl = read_newline(fd) ) > 0)
    {
        i++;
    }


    ///printf("rnl: %d, rt: %d, i: %d\n", rnl, rt, i);

    num = i + 1;

    if (rnl != -1 || rt == 0 || num > 26 || num < 1)
        print_error();

    //printf("limbo\n");

    define_g_tminos();
    i = 0;
	while (i < num)
    {
        sum = 0;
        j = 0;
	    while (j < TMINO_STR_LEN)
	        sum += array[i][j++];
	    if (sum != (('.' * 12) + ('#' * 4)))
            print_error();
        shift_up_left(array[i]);

        /// printf("type : %d\n", define_tetrimino(array[i]));

        if (define_tetrimino(array[i]) < 0)
            print_error();
        mino_to_letter(array[i], i);
	    i++;
    }


	start(array, num);

	//printf("\nbest size = %d\n", g_best_perimeter);
	// print_field(g_field_best, g_best_perimeter);
	return (0);
}
