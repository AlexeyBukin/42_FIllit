/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:14:20 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/28 13:41:42 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"

//int            g_field_size = 12;
//int            g_field_str_len = 144;

//extern int          g_best_rang;
//extern int          g_best_perimeter;
//extern t_field		g_best_field;

//extern int g_field_size;
//extern int g_field_str_len;

void    start(t_mino *array, int mino_num)
{
   // int         types[mino_num];
  //  int         if_any_not_empty = 0;
    t_field		field;
    int         i;

    define_g_tminos();
    i = 0;
    while (i < mino_num)
    {
        shift_up_left(array[i]);
        //types[i] = define_tetrimino(array[i]);
//        if (types[i] < 13)
//        {
//            if_any_not_empty = 1;
//        }
        mino_to_letter(array[i], i);
        i++;
    }



    //calculate optomal boundary
    calculate_and_set_boundary(mino_num);

    init_field(field);
    init_field(g_best_field);

    i = 0;
    while (i < mino_num)
    {
        tmino_swap(array[i], array[0]);
//        if (if_any_not_empty == 1 && types[i] > 12)
//        {
//            i++;
//            continue ;
//        }
        stack(field, 0, array[0]);
        rec_puzzle(field, &(array[1]), mino_num - 1);
        delete_from_field(field, 0, array[0]);
        i++;
    }
}

void        calculate_and_set_boundary(int mino_num)
{
    int     val;

    val = 1;
    while (val * val < mino_num * 4)
        val++;
    g_best_perimeter = val + 2;
    g_field_size = val + 5;
    g_field_str_len = g_field_size * g_field_size;
    g_best_rang = -1;
}


void	    init_field(t_field field)
{
    int 	i;

    i = 0;
    while (i < g_field_str_len)
    {
        field[i] = '.';
        i++;
    }
}