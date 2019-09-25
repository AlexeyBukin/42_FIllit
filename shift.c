/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:57:19 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/22 18:51:26 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"
#include <stdio.h>

void	shift_up(t_mino tmino)
{
	int		j;
	int		i;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			tmino[i * 4 + j] = tmino[(i + 1) * 4 + j];
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 4)
	{
		tmino[12 + j] = '.';
		j++;
	}
}

void	shift_left(t_mino tmino)
{
	int		j;
	int		i;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			tmino[j * 4 + i] = tmino[j * 4 + (i + 1)];
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 4)
	{
		tmino[j * 4 + 3] = '.';
		j++;
	}
}

void	shift_up_left(t_mino tmino)
{
	int 	is_empty;
	int		j;
	int		i;

	j = 0;
	is_empty = 1;
	while (j < 4)
	{
		i = 0;
		is_empty = 1;
		while (i < 4)
		{
			if (tmino[i] == '#')
				is_empty = 0;
			i++;
		}
		if (is_empty == 1)
			shift_up(tmino);
		i = 0;
		is_empty = 1;
		while (i < 4)
		{
			if (tmino[i * 4] == '#')
				is_empty = 0;
			i++;
		}
		if (is_empty == 1)
			shift_left(tmino);
		j++;
	}
}