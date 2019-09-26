/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:54:44 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/25 21:11:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"

#include <stdio.h>

extern int			g_best_perimeter;
extern t_field		g_best_field;



int		main(int argc, char **argv)
{
//	t_field		a;
//
//	init_field(&a);
//	//print_field(a, 3);
//	t_mino		m;
//	ft_memcpy(m, "####............", 16);
//	stack(&a, 0, m);
//
//	print_field(a, 16);
//	printf("\n");
//
//	int s = find_perimiter_size(a);
//	printf("size = %d\n", s);

	//int 	int_arr[26];
	t_mino	array[26];
	int 	i;
	int 	num;
	int 	fd;

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

	num = i;
	i = 0;
	while (i < num)
	{
		shift_up_left(array[i]);
		mino_to_letter(array[i], i);
		i++;
	}

	t_field		test_field;

	printf("\nnum = %d\n", num);
	//t_mino		array[3];
	//ft_memcpy(array[0], "####............", 16);
	//ft_memcpy(array[1], "#...#...#...#...", 16);
	//ft_memcpy(array[2], ".#..##...#......", 16);

	//mino_to_letter(array[0], 0);
	//mino_to_letter(array[1], 1);
	//mino_to_letter(array[2], 2);

	init_field(test_field);
	//init_field(g_best_field);
	rec_puzzle(test_field, array, i);
	//rec_puzzle(test_field, array, 3);

	printf("\nbest size = %d\n", g_best_perimeter);
	print_field(g_best_field, 8);
	return (0);

//	int 	int_arr[26];
//	t_mino	array[26];
//	int 	i;
//	int 	num;
//	int 	fd;
//
//	if (argc != 2)
//	{
//		print_usage();
//		return (0);
//	}
//	fd = open(argv[1], O_RDONLY);
//	i = -1;
//	while (++i < 26)
//	{
//		if (!read_tmino(fd, &(array[i])))
//			break ;
//		read_newline(fd);
//	}
//	define_g_tminos();
//	num = i;
//	i = 0;
//	while (i < num)
//	{
//		int_arr[i] = define_tetrimino(&(array[i]));
//		if (int_arr[i] < 0)
//		{
//			print_error();
//			return (0);
//		}
//		i++;
//	}
//	i = 0;
//	while (i < num)
//	{
//		printf("%d) type: %d\n", i, int_arr[i]);
//		print_tmino(array[i]);
//		i++;
//	}
//	return (0);
}

int		read_newline(int fd)
{
	int 	res;
	char	n;

	res = read(fd, &n, 1);
	if (res == 1 && n == '\n')
		return (1);
	return (0);
}

int		read_tmino(int fd, t_mino tmino)
{
	char	buffer[20];

	if (read(fd, buffer, 20) != 20)
		return (0);
	tmino[0] = buffer[0];
	tmino[1] = buffer[1];
	tmino[2] = buffer[2];
	tmino[3] = buffer[3];
	tmino[4] = buffer[5];
	tmino[5] = buffer[6];
	tmino[6] = buffer[7];
	tmino[7] = buffer[8];
	tmino[8] = buffer[10];
	tmino[9] = buffer[11];
	tmino[10] = buffer[12];
	tmino[11] = buffer[13];
	tmino[12] = buffer[15];
	tmino[13] = buffer[16];
	tmino[14] = buffer[17];
	tmino[15] = buffer[18];
	return (1);
}
