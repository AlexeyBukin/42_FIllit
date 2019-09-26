/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:57:19 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/26 14:54:28 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"
#include <stdio.h>

void	print_tmino(t_mino tmino)
{
	int 	i;

	i = 0;
	while(i < 16)
	{
		if (i % 4 == 0)
		{    ///
			print_step("");
		}
		printf("%c", tmino[i]);
		if (i % 4 == 3)
			printf("\n");
		i++;
	}
}

void	print_field(t_field field, int	size)
{
	int 	j;
	int 	i;

	char *colors[10];

	colors[0] = "[0;31m";
    colors[1] = "[0;32m";
    colors[2] = "[0;33m";
    colors[3] = "[0;34m";
    colors[4] = "[0;35m";
    colors[5] = "[0;36m";

//    colors[6] = "[1;31m";
//    colors[7] = "[0;31m";
//    colors[8] = "[0;31m";
//    colors[9] = "[0;31m";

	i = 0;
	while(i < size)
	{
		j = 0;

		///
		print_step("");

		while (j < size)
		{
		    if (field[FIELD_SIZE * i + j] <= 'Z' && field[FIELD_SIZE * i + j] >= 'A')
            {

		        printf("%s%s", "\033", colors[field[FIELD_SIZE * i + j] - 'A']);
                printf("%c", field[FIELD_SIZE * i + j]);
                printf("\033[0m");
            }
		    else
            {
                printf("%c", field[FIELD_SIZE * i + j]);
            }

			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_usage()
{
	printf("usage: ./fillit [tetrimino file]\n");
}

void	print_error()
{
	printf("error: wrong input\n");
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