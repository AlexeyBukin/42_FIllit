/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:21:09 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/26 15:09:13 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"
#include <stdio.h>

//TODO krasivo size + 1
int		is_perimiter_empty(t_field field, int size)
{
	int		i;

	i = 0;
	while (field[FIELD_SIZE * i + size] == '.' && i < size + 1)
		i++;
	if (i != size + 1)
		return (0);
	i = 0;
	while (field[FIELD_SIZE * size + i] == '.' && i < size + 1)
		i++;
	if (i != size + 1)
		return (0);
	return (1);
}

/* функция возвращает расстояние первой точки
 * от верхнего левого угла
 *
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

void		stack(t_field field, int index, t_mino mino)
{
	int		var;
	int 	i;

	i = 0;
	while (i < 16)
	{
		var = index + i % TMINO_SIZE + FIELD_SIZE * (i / TMINO_SIZE);
		//field[index + i % TMINO_SIZE + FIELD_SIZE * (i / TMINO_SIZE)] = mino[i];
		if (field[var] == '.')
			field[var] = mino[i];
		i++;
	}
}

int		try_stack(t_field field, int index, t_mino mino)
{
	int		index_to;
	int 	i;

	i = 0;
	while (i < 16)
	{
		if (mino[i] != '.')
		{
			index_to = index + i % TMINO_SIZE + FIELD_SIZE * (i / TMINO_SIZE);
			if (field[index_to] != '.')
			{
				return (0);
			}
		}
		i++;
	}
	stack(field, index, mino);
	return (1);
}

//// *try_stack check*
//int main(void)
//{
//	t_field		test_field;
//
//	t_mino		array[3];
//	ft_memcpy(array[0], "####............", 16);
//	ft_memcpy(array[1], "#...#...#...#...", 16);
//	ft_memcpy(array[2], ".#..##...#......", 16);
//
//	mino_to_letter(array[0], 0);
//	mino_to_letter(array[1], 1);
//	mino_to_letter(array[2], 2);
//
//	init_field(test_field);
//
//	printf("try_stack 1: %d\n", try_stack(test_field, 0, array[2]));
//	print_field(test_field, 8);
//	printf("try_stack 2: %d\n", try_stack(test_field, 32, array[1]));
//	print_field(test_field, 8);
//	printf("try_stack 2: %d\n", try_stack(test_field, 0, array[0]));
//	print_field(test_field, 8);
//
//	return (0);
//}

int			g_best_perimeter = 16;
t_field		g_best_field;

extern int			g_step;



void		rec_puzzle(t_field field, t_mino *tminos, int mino_num)
{
	int 		a;
	int 		j;
	int 		i;
	int 		perimiter_size;
	t_mino		active_mino;
	t_mino		next_array[mino_num];
	t_field		local_field;

    //print_field(local_field, 8);



	perimiter_size = find_perimiter_size(field);
	//if (perimiter_size <= 1)
	//	perimiter_size = 0;

	print_step("");
	printf("p_size: %d, mino_num: %d\n", perimiter_size, mino_num);

	if (perimiter_size > g_best_perimeter)
		return ;

	///
	//g_step ++;
    ft_memcpy(local_field, field, FIELD_STR_LEN);

	if (mino_num == 0)
	{
		print_step("endpoint\n");
		if (perimiter_size < g_best_perimeter)
		{
			g_best_perimeter = perimiter_size;
			ft_memcpy(g_best_field, field, FIELD_STR_LEN);

			print_step("congrats!!! - better size\n");
			///
			//print_field(g_best_field, 8);

		}
		else if (perimiter_size == g_best_perimeter)
        {
		    if (get_rang(field, perimiter_size) > get_rang(g_best_field, perimiter_size))
            {
                ft_memcpy(g_best_field, field, FIELD_STR_LEN);

                print_step("congrats !!! - better rang\n");
            }


        }
		///
        print_field(local_field, 8);

		return;
	}

	print_step("call\n");

	//ft_memcpy(local_field, field, FIELD_STR_LEN);
	i = 0;

	//perimiter_size = find_perimiter_size(field);


	print_field(local_field, 8);

	while (i < mino_num)
	{
		///
		//print_step("");
		//printf("%d) while iter, smaller then %d\n", i, mino_num);

		ft_memcpy(active_mino, tminos[i], TMINO_STR_LEN);



		j = 0;
		a = 0;
		if (mino_num > 1)
		{
			//print_step("next array: ");
			//printf("| i: %d \n", i);
			while (j < mino_num - 1)
			{
				if (a == i)
					a++;
				//print_step("");
				//printf("copy from %d to %d\n", j, a);
				ft_memcpy(next_array[j], tminos[a], TMINO_STR_LEN);
				//next_array[j] = tminos[a];
				///
				print_tmino(next_array[j]);

				a++;
				j++;
			}
		}
		//print_step("no crash 1: \n");

		{ //perimiter iteration "try stack"
			//print_step("cycling over, ");
			//printf("per_size: %d\n", perimiter_size);
			ft_memcpy(local_field, field, FIELD_STR_LEN);
			//print_field(local_field, 16);

			j = 0;
			//while (j <= perimiter_size)
			while (j < (perimiter_size + 1) * (perimiter_size + 1))
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
				if (try_stack(local_field, index, active_mino))
				{
					//print_step("no crash 3: \n");
					//print_step("giving this: \n");
					//print_field(local_field, 8);
					g_step++;
					rec_puzzle(local_field, next_array, mino_num - 1);
					g_step--;
				}
				//print_step("no crash 2: \n");
				ft_memcpy(local_field, field, FIELD_STR_LEN);

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
	///
	/// return (0);
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

	return (y * FIELD_SIZE + x);
}

//int		main(void)
//{
//	//int i = 0;
//	//get_index_by_num(5, 5);
//	get_index_by_num(7, 3);
//	get_index_by_num(6, 3);
//	return (0);
//}

int		find_perimiter_size(t_field field)
{
	int 	step;
	int 	size;

	step = 4;
	size = 8;
	while (step > 0)
	{
		if (is_perimiter_empty(field, size))
		{
			if (!is_perimiter_empty(field, size - 1))
			{
				return (size);
			}
			size -= step;
		}
		else
		{
			size += step;
		}
		step /= 2;
	}
	return (size);
}

void		mino_to_letter(t_mino mino, int num)
{
	int 	i;

	i = 0;
	while (i < TMINO_STR_LEN)
	{
		if (mino[i] != '.')
		{
			mino[i] = 'A' + num;
		}
		i++;
	}
}

void	init_field(t_field field)
{
	int 	i;

	i = 0;
	while (i < 256)
	{
		field[i] = '.';
		i++;
	}
}