/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:57:19 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/01 21:23:35 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"
#include <stdio.h>

//extern int g_field_size;
//extern int g_field_str_len;

void	print_tmino_array(t_mino *array, int num)
{
    int     j;
    int 	i;

    i = 0;
    while(i < TMINO_SIZE)
    {
        j = 0;
        print_step("");
        while (j < num)
        {
            int a = i * TMINO_SIZE;
            printf("%c%c%c%c  ", array[j][a + 0], array[j][a + 1], array[j][a + 2], array[j][a + 3] );
            j++;
        }
        printf("\n");
        i++;
    }
}

void	print_tmino(t_mino tmino)
{
	int 	i;

	i = 0;
	while(i < TMINO_STR_LEN)
	{
		if (i % TMINO_SIZE == 0)
		{    ///
			print_step("");
		}
		printf("%c", tmino[i]);
		if (i % TMINO_SIZE == (TMINO_SIZE - 1))
			printf("\n");
		i++;
	}
}

void	print_field(t_field field, int	size)
{
    int 	j;
    int 	i;

    i = 0;
    while(i < size)
    {
        j = 0;
        while (j < size)
        {
            printf("%c", field[g_field_size * i + j]);
            j++;
        }
        printf("\n");
        i++;
    }
    exit(0);
}



//void	print_field(t_field field, int	size)
//{
//
//    static  int print_time = 0;
//
//    int 	j;
//	int 	i;
//
//	print_time++;
//	if (print_time > 50)
//	    return;
//
//	char *colors[10];
//
//	colors[0] = "[0;31m";
//    colors[1] = "[0;32m";
//    colors[2] = "[0;33m";
//    colors[3] = "[0;34m";
//    colors[4] = "[0;35m";
//    colors[5] = "[0;36m";
//
//    colors[6] = "[1;31m";
//    colors[7] = "[1;32m";
//    colors[8] = "[01;33m";
//    colors[9] = "[1;35m";
//
//	i = 0;
//	while(i < size + 2)
//	{
//		j = 0;
//
//		///
//		print_step("");
//
//		while (j < size + 2)
//		{
//		    if (field[g_field_size * i + j] <= 'Z' && field[g_field_size * i + j] >= 'A')
//            {
//
//		        printf("%s%s", "\033", colors[field[g_field_size * i + j] - 'A']);
//                printf("%c ", field[g_field_size * i + j]);
//                printf("\033[0m");
//            }
//		    else
//            {
//                printf("%c ", field[g_field_size * i + j]);
//            }
//
//			j++;
//		}
//		printf("\n");
//		i++;
//	}
//}

void	print_usage()
{
    write(1, "usage: ./fillit [file]\n", ft_strlen("usage: ./fillit [file]\n"));
	exit(0);
}

void	print_error()
{
    write(1, "error\n", ft_strlen("error\n"));
	exit(0);
}

int		g_step = 0;

void		print_step(char *str)
{
	int 	i = 0;

	while (i < g_step)
	{
		printf("        ");
		i++;
	}
	printf("%s", str);
}