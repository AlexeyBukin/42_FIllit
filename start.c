/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:14:20 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/01 21:14:43 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"

t_field		        g_field_best;

void    start(t_mino *array, int mino_num)
{
    t_field		        field;
    //t_field		        field_best;
    register int        i;
    register int        k;

    calculate_and_set_boundary(mino_num);

    init_field(field);
    //init_field(g_best_field);

    int j = 10;
    while (j > 1)
    {
        //g_best_perimeter = j;
        // rec_puzzle(field, array, mino_num, j);
        init_field(field);
        //init_field(g_field_best);

        i = 0;
       //printf("j: %d\n", j);

        int  one_found = 0;


//        stack(field, 0, array[0]);
//        if (rec_puzzle(field, &(array[1]), mino_num - 1, j) == 1)
//        {
//            j--;
//            continue;
//        }
//
//        if (rec_puzzle(field, array, mino_num, j) == 0)
//        {
//            //should_break_i = 1;
//            print_field(g_field_best, j + 1);
//            //break;
//            exit (0);
//        }

// i < mino_num

        while (i < 1)
        {
           //printf("    i: %d\n", i);

            tmino_swap(array[i], array[0]);
            k = 0;


            // k < j
            while (k < 1)
            {
            //k = 0;

                stack(field, k, array[0]);

                if (rec_puzzle(field, &(array[1]), mino_num - 1, j) == 1)
                {
                    one_found = 1;
                    //print_field(field, j);
                    break;
                    //exit (0);
                }
                delete_from_field(field, k, array[0]);

                k++;
            }

            if (one_found == 1)
                break;

            //printf("    not as easy\n");

            one_found = 0;
            init_field(field);

            //init_field(field);
            rotate_array(array, mino_num);

            i++;
        }

        if (one_found == 1)
        {
            j--;
            continue;
        }

        //if (i == mino_num && one_found == 0)
//        if (i == mino_num)
//        {
//            printf ("winner - 2!!!\n");
//            print_field(g_field_best, j + 1);
//            return ;
//        }

        if (rec_puzzle(field, array, mino_num, j) == 1)
        {
            //printf ("winner - 1!!!\n");
            print_field(g_field_best, j);
            return ;
        }
        else
        {
            //printf ("winner - 2!!!\n");
            print_field(g_field_best, j + 1);
            return ;
        }


        ///printf("j: %d - end\n", j);

        j--;
    }
}

void        calculate_and_set_boundary(int mino_num)
{
    register int     val;

    val = 1;
    while (val * val < mino_num * 4)
        val++;
    //g_best_perimeter = val + 2;
    g_field_size = val + 5;
    g_field_str_len = g_field_size * g_field_size;
    //g_best_rang = -1;
}


void	    init_field(t_field field)
{
    register int 	i;

    i = 0;
    while (i < 256)
    {
        field[i] = '.';
        i++;
    }
//    while (i < g_field_str_len)
//    {
//        field[i] = '.';
//        i++;
//    }
}