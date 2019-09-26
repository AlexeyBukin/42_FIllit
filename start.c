/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:14:20 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/26 19:40:02 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"

extern t_field		g_best_field;

void    start(t_mino *array, int mino_num)
{
    t_field		field;


    t_mino  empty;
    t_mino  next_array[mino_num * 2];
    int     i;

    i = 0;
    while (i < mino_num)
    {
        shift_up_left(array[i]);
        mino_to_letter(array[i], i);
        i++;
    }

    init_field(field);
    init_field(g_best_field);

    if (mino_num == 1)
    {
        stack(g_best_field, 0, array[0]);
        return ;
    }

    ft_memcpy(empty, "..................", TMINO_STR_LEN);

    i = 0;
    while (i < mino_num * 2)
    {
        ft_memcpy(next_array[i], array[i % mino_num], TMINO_STR_LEN);
        //next_array[i] = array[i % mino_num];
        i++;
    }

    i = 0;
    while (i < mino_num - 1)
    {
        stack(field, 0, array[i]);
        rec_puzzle(field, &(next_array[i + 1]), mino_num - 1);
        init_field(field);
        i++;
    }

    //rec_puzzle(test_field, array, mino_num - 1);
}