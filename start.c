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

void    start(t_mino *array, int mino_num)
{
    t_field		        field;
    register int        i;

    i = 0;
    while (i < mino_num)
    {
        shift_up_left(array[i]);
        mino_to_letter(array[i], i);
        i++;
    }
    calculate_and_set_boundary(mino_num);

    init_field(field);
    init_field(g_best_field);

    i = 0;
    while (i < mino_num)
    {
        tmino_swap(array[i], array[0]);
        stack(field, 0, array[0]);


        print_field(field, g_field_size);
        print_tmino_array(array, mino_num);


        rec_puzzle(field, &(array[1]), mino_num - 1);
        delete_from_field(field, 0, array[0]);
        i++;
    }
}

void        calculate_and_set_boundary(int mino_num)
{
    register int     val;

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
    register int 	i;

    i = 0;
    while (i < g_field_str_len)
    {
        field[i] = '.';
        i++;
    }
}