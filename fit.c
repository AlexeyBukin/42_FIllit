/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:21:09 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/28 12:50:33 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"

extern int g_field_size;
extern int g_field_str_len;

/*
 * function checks if perimiter of given size is empty
 *
 * функция проверяет, пуст ли периметр заданного размера
 */

int		is_perimiter_empty(t_field field, int size)
{
    register int 	sum;
    register int 	i;

	sum = 0;
	i = 0;
	while (i < size + 1)
    {
        sum += field[g_field_size * i + size];
        i++;
    }
	if (sum != '.' * (size + 1))
        return (0);
	sum = 0;
	i = 0;
	while (i < size)
	{
        sum += field[g_field_size * size + i];
        i++;
    }
	return (sum == ('.' * (size)));
}

/*
 * функция get_rang() возвращает расстояние первой точки
 * от верхнего левого угла в условных единицах
 */

int     get_rang(t_field field, int perim)
{
    char            perim_sqr;
    register int 	i;
    register int 	index;

    i = 0;
    perim_sqr = perim * perim;
    while (i < perim_sqr)
    {
        index = get_index_by_num(i, perim);
        if (field[index] == '.')
            return (i);
        i++;
    }
    return (i + 1);
}

/*
 *  function adds one tetrimino to a field
 */

void		stack(t_field field, int index, t_mino mino)
{
    register int 	i;

	i = 0;
	while (i < TMINO_STR_LEN - 3)
	{
		if (mino[i] != '.')
            field[index + (i & 3) + g_field_size * (i >> 2)] = mino[i];
		i++;
	}
}

/*
 * function removes one tetrimino from the field
 */

void        delete_from_field(t_field field, int index, t_mino mino)
{
    register int 	i;

    i = 0;
    while (i < TMINO_STR_LEN - 3)
    {
        if (mino[i] != '.')
            field[index + (i & 3) + g_field_size * (i >> 2)] = '.';
        i++;
    }
}

/*
 * function checks if a tetrimino can be added, if so, adds
 * one tetrimino with a call to stack()
 */

int		try_stack(t_field field, int index, t_mino mino)
{
    register int 	i;

	i = 0;
	while (i < TMINO_STR_LEN - 3)
	{
		if (mino[i] != '.' && field[index + (i & 3) + g_field_size * (i >> 2)] != '.')
		    return (0);
		i++;
	}
	stack(field, index, mino);
	return (1);
}

void    tmino_swap(t_mino t1, t_mino t2)
{
    char            buf;
    register int 	i;

    i = 0;
    while (i < TMINO_STR_LEN - 3)
    {
        buf = t1[i];
        t1[i] = t2[i];
        t2[i] = buf;
        i++;
    }
}

extern int			g_step;


void		rec_puzzle(t_field field, t_mino *tminos, int mino_num)
{
    int         local_rang;
	register int 		j;
	register int 		i;
	int 		perimiter_size;



	perimiter_size = find_perimiter_size(field);

	if (perimiter_size > g_best_perimeter)
		return ;

	if (mino_num == 0)
	{
		if (perimiter_size < g_best_perimeter)
		{
			g_best_perimeter = perimiter_size;
			ft_memcpy(g_best_field, field, g_field_str_len);
			g_best_rang = get_rang(g_best_field, perimiter_size);
			return ;
		}
        local_rang = get_rang(field, perimiter_size);
        if (local_rang > g_best_rang)
        {
            ft_memcpy(g_best_field, field, g_field_str_len);
            g_best_rang = local_rang;
        }
		return ;
	}

    //print_field(field, g_field_size);
    //print_tmino_array(tminos, mino_num);

	i = 0;
	while (i < mino_num)
    {
        tmino_swap(tminos[i], tminos[0]);



        int once_stacked = 0;

        j = 0;

        //int limit = (perimiter_size + 1) * (perimiter_size + 2) / 2;
        int limit = (perimiter_size) * (perimiter_size + 1) / 2;
        int index;

        //limit = perimiter_size * perimiter_size - 1;

        while (j < limit)
        {
            //index = get_index_by_num(j, (perimiter_size + 1));
            index = get_index_by_num(j, perimiter_size);
            if (try_stack(field, index, tminos[0]) )
            {
                once_stacked = 1;
                //g_step++;



                rec_puzzle(field, tminos + 1, mino_num - 1);
                delete_from_field(field, index, tminos[0]);


                //g_step--;
            }
            j++;
        }

//        index = get_index_by_num(j, (perimiter_size + 1));
//        if (try_stack(field, index, tminos[0]) )
//        {
//            once_stacked = 1;
//            //g_step++;
//            rec_puzzle(field, tminos + 1, mino_num - 1);
//            delete_from_field(field, index, tminos[0]);
//            //g_step--;
//        }
//
//        index = get_index_by_num(j, (perimiter_size + 1));
//        if (try_stack(field, index, tminos[0]) )
//        {
//            once_stacked = 1;
//            //g_step++;
//            rec_puzzle(field, tminos + 1, mino_num - 1);
//            delete_from_field(field, index, tminos[0]);
//            //g_step--;
//        }




        j = (perimiter_size) * (perimiter_size + 1) / 2;
        //j++;
        limit = (perimiter_size + 1) * (perimiter_size + 2) / 2;
        //limit--;
        while (j < limit)
        {
            index = get_index_by_num(j, (perimiter_size + 1));
            if (try_stack(field, index, tminos[0]) )
            {
                //g_step++;
                rec_puzzle(field, &(tminos[1]), mino_num - 1);
                delete_from_field(field, index, tminos[0]);
                //g_step--;
            }
            j++;
        }

        i++;
    }

    rotate_array(tminos, mino_num);
}

void    rotate_array(t_mino *array, int num)
{
    t_mino buf;
    register int i;

    ft_memcpy(buf, array[0], TMINO_STR_LEN - 3);
    i = 0;
    while (i < num - 1)
    {
        ft_memcpy(array[i], array[i + 1], TMINO_STR_LEN - 3);
        i++;
    }
    ft_memcpy(array[i], buf, TMINO_STR_LEN - 3);
}

int		        size_bounds[17] = {0, 0, 2, 5, 9, 14, 20, 27, 35, 44, 54, 65, 77, 90, 104, 119, 135};

int		get_index_by_num(int num, int size)
{
    register int    i;
    register int 	x;
    register int 	y;
    register int 	abc;

	if (num == 0)
		return (0);

	i = 0;
	while (num > size_bounds[i + 1])
		i++;

	x = num - size_bounds[i] - 1;
	y = i - (num - size_bounds[i] - 1);

	if (num > size_bounds[size])
	{
		abc = size - 1;
		while (num > size_bounds[size])
		{
			num = num - abc;
			abc--;
		}
		i = 0;
		while (num > size_bounds[i + 1])
			i++;

		x = num - size_bounds[i] - 1;
		y = i + (size - 1 - abc) - (num - size_bounds[i] - 1);
	}

	return (y * g_field_size + x);
}


int		find_perimiter_size(t_field field)
{
    register int     size;

    size = g_field_size - 1;
    while (is_perimiter_empty(field, size))
    {
        size--;
    }
    return (size + 1);
}

void		mino_to_letter(t_mino mino, int num)
{
	register int 	i;

	i = 0;
	while (i < TMINO_STR_LEN - 3)
	{
		if (mino[i] != '.')
			mino[i] = 'A' + num;
		i++;
	}
}
