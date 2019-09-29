/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_tetrimino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:42:42 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/28 13:43:27 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"

int		count_chars(t_mino tmino, char c)
{
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	while(i < TMINO_STR_LEN)
	{
		if (tmino[i] == c)
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

int		ft_tmino_cmp(t_mino t1, t_mino t2)
{
    register int        sum1;
    register int        sum2;
	register int		i;

	//print_tmino(t1);
	i = 0;
	sum1 = 0;
	sum2 = 0;
	while (i < TMINO_SIZE)
    {
	    sum1 += t1[i];
        sum2 += t2[i];
	    i++;
    }
	return (sum1 == sum2);
}

int		define_tetrimino(t_mino tmino)
{
    register int			i;

	if (count_chars(tmino, '.') != 12)
		return (-1);
	shift_up_left(tmino);
    // print_tmino(tmino);
	i = 0;
	while(i < T_MINO_TYPES)
	{
		if (ft_tmino_cmp(tmino, g_tminos[i]) == 1)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	define_g_tminos(void)
{
    ft_memcpy(g_tminos[0], "##..##..........", 16);
    ft_memcpy(g_tminos[1], "####............", 16);
    ft_memcpy(g_tminos[2], "#...#...#...#...", 16);
    ft_memcpy(g_tminos[3], "#...##...#......", 16);
    ft_memcpy(g_tminos[4], "##...##.........", 16);
    ft_memcpy(g_tminos[5], "#...##..#.......", 16);
    ft_memcpy(g_tminos[6], "###..#..........", 16);
    ft_memcpy(g_tminos[7], "##..#...#.......", 16);
    ft_memcpy(g_tminos[8], "###...#.........", 16);
    ft_memcpy(g_tminos[9], "#...###.........", 16);
    ft_memcpy(g_tminos[10], "##...#...#......", 16);
    ft_memcpy(g_tminos[11], "#...#...##......", 16);
    ft_memcpy(g_tminos[12], "###.#...........", 16);

    ft_memcpy(g_tminos[13], "..#.###.........", 16);
    ft_memcpy(g_tminos[14], ".##.##..........", 16);
    ft_memcpy(g_tminos[15], ".#..##..#.......", 16);
    ft_memcpy(g_tminos[16], ".#..###.........", 16);
    ft_memcpy(g_tminos[17], ".#..##...#......", 16);
    ft_memcpy(g_tminos[18], ".#...#..##......", 16);

}

//void	define_g_tminos(void)
//{
//	ft_memcpy(g_tminos[0], "##..##..........", 16);
//	ft_memcpy(g_tminos[1], "####............", 16);
//	ft_memcpy(g_tminos[2], "#...#...#...#...", 16);
//	ft_memcpy(g_tminos[3], ".##.##..........", 16);
//	ft_memcpy(g_tminos[4], "#...##...#......", 16);
//	ft_memcpy(g_tminos[5], "##...##.........", 16);
//	ft_memcpy(g_tminos[6], ".#..##..#.......", 16);
//	ft_memcpy(g_tminos[7], ".#..###.........", 16);
//	ft_memcpy(g_tminos[8], "#...##..#.......", 16);
//	ft_memcpy(g_tminos[9], "###..#..........", 16);
//	ft_memcpy(g_tminos[10], ".#..##...#......", 16);
//	ft_memcpy(g_tminos[11], "##..#...#.......", 16);
//	ft_memcpy(g_tminos[12], "###...#.........", 16);
//	ft_memcpy(g_tminos[13], ".#...#..##......", 16);
//	ft_memcpy(g_tminos[14], "#...###.........", 16);
//	ft_memcpy(g_tminos[15], "##...#...#......", 16);
//	ft_memcpy(g_tminos[16], "..#.###.........", 16);
//	ft_memcpy(g_tminos[17], "#...#...##......", 16);
//	ft_memcpy(g_tminos[18], "###.#...........", 16);
//}