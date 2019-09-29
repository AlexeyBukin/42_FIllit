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
    int     sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < size + 1)
    {
        sum += field[g_field_size * i + size];
        i++;
    }
	i = 0;
	while (i < size)
	{
        sum += field[g_field_size * size + i];
        i++;
    }
	return (sum == ('.' * (size + size + 1)));
}

/*
 * функция get_rang() возвращает расстояние первой точки
 * от верхнего левого угла в условных единицах
 */

int     get_rang(t_field field, int perim)
{
    int     i;
    int     index;

    i = 0;
    while (i < perim * perim)
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
	int		var;
	int 	i;

	i = 0;
    // (i < TMINO_STR_LEN)
	while (i < TMINO_STR_LEN - 3)
	{

		//field[index + i % TMINO_SIZE + FIELD_SIZE * (i / TMINO_SIZE)] = mino[i];
		if (mino[i] != '.')
        {
            var = index + i % TMINO_SIZE + g_field_size * (i / TMINO_SIZE);
            field[var] = mino[i];
        }
		i++;
	}
}

/*
 * function removes one tetrimino from the field
 */

void        delete_from_field(t_field field, int index, t_mino mino)
{
    int		index_to;
    int 	i;

    i = 0;
    while (i < TMINO_STR_LEN - 3)
    {
        if (mino[i] != '.')
        {
            index_to = index + i % TMINO_SIZE + g_field_size * (i / TMINO_SIZE);
            field[index_to] = '.';
        }
        i++;
    }
}

/*
 * function checks if a tetrimino can be added, if so, adds
 * one tetrimino with a call to stack()
 */

int		try_stack(t_field field, int index, t_mino mino)
{
	int 	i;

	i = 0;
	while (i < TMINO_STR_LEN - 3)
	{
		if (mino[i] != '.')
		{
			if (field[index + i % TMINO_SIZE + g_field_size * (i / TMINO_SIZE)] != '.')
			{
				return (0);
			}
		}
		i++;
	}
	stack(field, index, mino);
	return (1);
}

void    tmino_swap(t_mino t1, t_mino t2)
{
    ft_memcpy(g_tmino_buf, t1, TMINO_STR_LEN);
    ft_memcpy(t1, t2, TMINO_STR_LEN - 3);
    ft_memcpy(t2, g_tmino_buf, TMINO_STR_LEN - 3);
}

//int			g_best_perimeter = 16;
//t_field		g_best_field;
//int         g_best_rang = -1;

extern int			g_step;


void		rec_puzzle(t_field field, t_mino *tminos, int mino_num)
{
    int         local_rang;
	//int 		a;
	int 		j;
	int 		i;
	int 		perimiter_size;
	// t_mino		active_mino;
	// t_mino		next_array[mino_num * 2];
	// t_field		local_field;

    //print_field(local_field, 8);



	perimiter_size = find_perimiter_size(field);
	//if (perimiter_size <= 1)
	//	perimiter_size = 0;

	/// get-back
	//print_step("");
	//printf("p_size: %d, mino_num: %d\n", perimiter_size, mino_num);

	if (perimiter_size > g_best_perimeter)
		return ;

	///
	//g_step ++;
	//ft_memcpy(local_field, field, FIELD_STR_LEN);

	if (mino_num == 0)
	{
        /// get-back
        // print_step("endpoint\n");
		if (perimiter_size < g_best_perimeter)
		{
			g_best_perimeter = perimiter_size;
			ft_memcpy(g_best_field, field, g_field_str_len);
			g_best_rang = get_rang(g_best_field, perimiter_size);

			// print_step("congrats!!! - better size\n");
			///
			//print_field(g_best_field, 8);

		}
		else // if (perimiter_size == g_best_perimeter)
        {
		    local_rang = get_rang(field, perimiter_size);
		    if (local_rang > g_best_rang)
            {
                ft_memcpy(g_best_field, field, g_field_str_len);
                g_best_rang = local_rang;
                ///
                // print_step("congrats !!! - better rang\n");
            }
        }
		///
        /// get-back
        // print_field(g_best_field, 8);

		return ;
	}

	 // print_step("call\n");

	// ft_memcpy(local_field, field, g_field_str_len);
	i = 0;

    /// get-back
   // if (mino_num >= 1)
        //print_field(field, g_field_size);

//    i = 0;
//    while (i < mino_num * 2)
//    {
//        ft_memcpy(next_array[i], tminos[i % mino_num], TMINO_STR_LEN);
//        //next_array[i] = array[i % mino_num];
//        i++;
//    }

    // ft_memcpy(next_array[mino_num - 1], tminos[i], TMINO_STR_LEN);
   // if (mino_num >= 1){
//        print_step("");
//        printf("got mnum: %d\n", mino_num);
//        print_tmino_array(tminos, mino_num);
//        print_step("\n");
   // }

    i = 0;
	while (i < mino_num)
	{
        tmino_swap(tminos[i], tminos[0]);

//        j = 0;
//        printf("i = %d, before swap:\n", i);
//        while(j < mino_num)
//        {
//            print_tmino(next_array[j]);
//            //printf("\n");
//            j++;
//        }
//        printf("after swap\n");
//        tmino_swap(next_array[i], next_array[mino_num - 1]);
//        j = 0;
//        while(j < mino_num)
//        {
//            print_tmino(next_array[j]);
//            //printf("\n");
//            j++;
//        }
//        printf("\n\n");
		///
		//print_step("");
		//printf("%d) while iter, smaller then %d\n", i, mino_num);

		// ft_memcpy(active_mino, tminos[i], TMINO_STR_LEN);



//		j = 0;
//		a = 0;
//		if (mino_num > 1)
//		{
//			//print_step("next array: ");
//			//printf("| i: %d \n", i);
//			while (j < mino_num - 1)
//			{
//				if (a == i)
//					a++;
//				//print_step("");
//				//printf("copy from %d to %d\n", j, a);
//				ft_memcpy(next_array[j], tminos[a], TMINO_STR_LEN);
//				//next_array[j] = tminos[a];
//
//				/// get-back
//				// print_tmino(next_array[j]);
//
//				a++;
//				j++;
//			}
//		}


		//print_step("no crash 1: \n");

		{ //perimiter iteration "try stack"
			//print_step("cycling over, ");
			//printf("per_size: %d\n", perimiter_size);

			///
			/// ft_memcpy(local_field, field, g_field_str_len);

			//print_field(local_field, 16);

			j = 0;

//			int count_to = (perimiter_size + 1) * (perimiter_size + 1);
//
//			while (j < count_to)
//            {
//			    int index = j / (perimiter_size + 1) * g_field_size + j % (perimiter_size + 1);
//			    //printf("j: %d, index: %d, perim_size: %d, g_size: %d\n", j, index, perimiter_size, g_field_size);
//			    /// && find_perimiter_size(field) <= g_best_perimeter
//                if (try_stack(field, index, tminos[i]))
//                {
//                    //print_step("no crash 3: \n");
//                    //print_step("giving this: \n");
//                    //print_field(local_field, 8);
//                    g_step++;
//                    // rec_puzzle(local_field, next_array, mino_num - 1);
//                   // if (find_perimiter_size(field) <= g_best_perimeter)
//                    //{
//                        rec_puzzle(field, &(next_array[i + 1]), mino_num - 1);
//                   // }
//                    delete_from_field(field, index, tminos[i]);
//                    g_step--;
//                }
//                j++;
//            }

			//while (j <= perimiter_size)
			int limit = (perimiter_size + 1) * (perimiter_size + 2) / 2;
			while (j < limit)
			{
				//print_step("no crash 2: \n");
				///
				//local_field[FIELD_SIZE * j + perimiter_size] = '*';
				//print_step("sending: \n");
				//print_field(local_field, 16);
				//local_field[FIELD_SIZE * j + perimiter_size] = '.';
				///

				int index = get_index_by_num(j, (perimiter_size + 1));

				//print_step("");
				//printf("j: %d, x: %d, y: %d, index: %d\n", j, index % 16, index / 16, index);
				//if (try_stack(&local_field, FIELD_SIZE * j + perimiter_size, active_mino))
				/// if
				//if (try_stack(local_field, index, active_mino))
				if (try_stack(field, index, tminos[0]) )
				{
					//print_step("no crash 3: \n");
					//print_step("giving this: \n");
					//print_field(local_field, 8);
					g_step++;
					// rec_puzzle(local_field, next_array, mino_num - 1);
                   // if (find_perimiter_size(field) <= g_best_perimeter)
                   // {
                    rec_puzzle(field, &(tminos[1]), mino_num - 1);
                   /// rec_puzzle(field, &(next_array[i + 1]), mino_num - 1);
                   // }
                    delete_from_field(field, index, tminos[0]);
					g_step--;
				}
				//print_step("no crash 2: \n");
				/// ft_memcpy(local_field, field, g_field_str_len);

//				if (try_stack(local_field, FIELD_SIZE * perimiter_size + j, active_mino))
//				{
//					rec_puzzle(local_field, next_array, mino_num - 1);
//				}
//				ft_memcpy(local_field, field, FIELD_SIZE);

				j++;
			}

			

			//while ()
		}
		i++;
	}

    i = 0;
    while (i < mino_num - 1)
    {
        tmino_swap(tminos[i], tminos[i + 1]);
        i++;
    }
}

int		get_index_by_num(int num, int size)
{
	//int 	res;
	//int		sum;
	int 	i;
	int		size_bounds[17] = {0, 0, 2, 5, 9, 14, 20, 27, 35, 44, 54, 65, 77, 90, 104, 119, 135};
	//int 	size_bound;
	//int 	step;
	//int		level;
	int 	x;
	int 	y;
	//int 	fake_i;
	int 	abc;
	//int		iter_count;

	//iter_count = 0;
	if (num == 0)
		return (0);
	//size_bound = size_bounds[size];
	//printf("num before: %d\n", num);

	i = 0;
	while (num > size_bounds[i + 1])
		i++;

	x = num - size_bounds[i] - 1;
	y = i - (num - size_bounds[i] - 1);

	//printf("old x: %d\n\n", x);

	//fake_i = 0;

	if (num > size_bounds[size])
	{
		abc = size - 1;
		while (num > size_bounds[size])
		{
			num = num - abc;
			abc--;

			//printf("num: %d, abc: %d\n", num, abc);
		}

		//iter_count = size - 1 - abc;
		//printf("new iter_c: %d\n", iter_count);

		//fake i
		i = 0;
		while (num > size_bounds[i + 1])
			i++;

		x = num - size_bounds[i] - 1;
		y = i + (size - 1 - abc) - (num - size_bounds[i] - 1);

		//printf("\n\n");
	}

	//x = num - size_bounds[fake_i] - 1;

	//res = y * FIELD_SIZE + x;
	//res = (i - (num - size_bounds[i] - 1)) * FIELD_SIZE + (num - size_bounds[i] - 1);
	//printf("size_bound: %d, i = %d, x: %d, y: %d, fake_i: %d, res: %d, num: %d\n", size_bound, i, x, y, fake_i, res, num);

	//printf("size_bound: %d, i = %d, x: %d, y: %d, num: %d\n", size_bounds[size], i, x, y, num);

	return (y * g_field_size + x);
}


int		find_perimiter_size(t_field field)
{
    int     size;

    size = g_field_size - 1;
    while (is_perimiter_empty(field, size))
    {
        size--;
    }
    return (size + 1);
}

void		mino_to_letter(t_mino mino, int num)
{
	int 	i;

	i = 0;
    // (i < TMINO_STR_LEN)
	while (i < TMINO_STR_LEN - 3)
	{
		if (mino[i] != '.')
		{
			mino[i] = 'A' + num;
		}
		i++;
	}
}
