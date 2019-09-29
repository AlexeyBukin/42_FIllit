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

void	shift_up(t_mino tmino)
{
	int		j;
	int		i;

	i = 0;
	while (i < TMINO_SIZE - 1)
	{
		j = 0;
		while (j < TMINO_SIZE)
		{
			tmino[i * TMINO_SIZE + j] = tmino[(i + 1) * TMINO_SIZE + j];
			j++;
		}
		i++;
	}
	j = 0;
	while (j < TMINO_SIZE)
	{
		tmino[TMINO_SIZE * (TMINO_SIZE - 1) + j] = '.';
		j++;
	}
}

void	shift_left(t_mino tmino)
{
	int		j;
	int		i;

	i = 0;
	while (i < TMINO_SIZE - 1)
	{
		j = 0;
		while (j < TMINO_SIZE)
		{
			tmino[j * TMINO_SIZE + i] = tmino[j * TMINO_SIZE + (i + 1)];
			j++;
		}
		i++;
	}
	j = 0;
	while (j < TMINO_SIZE)
	{
		tmino[j * TMINO_SIZE + (TMINO_SIZE - 1)] = '.';
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
	while (j < TMINO_SIZE)
	{
		i = 0;
		is_empty = 1;
		while (i < TMINO_SIZE)
		{
			if (tmino[i] == '#')
				is_empty = 0;
			i++;
		}
		if (is_empty == 1)
			shift_up(tmino);
		i = 0;
		is_empty = 1;
		while (i < TMINO_SIZE)
		{
			if (tmino[i * TMINO_SIZE] == '#')
				is_empty = 0;
			i++;
		}
		if (is_empty == 1)
			shift_left(tmino);
		j++;
	}
}