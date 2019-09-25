/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:57:19 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/25 11:49:13 by kcharla          ###   ########.fr       */
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

	i = 0;
	while(i < size)
	{
		j = 0;

		///
		print_step("");

		while (j < size)
		{
			printf("%c", field[FIELD_SIZE * i + j]);
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