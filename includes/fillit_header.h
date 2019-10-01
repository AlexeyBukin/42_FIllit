/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:05:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/01 14:45:25 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_HEADER_H
# define FILLIT_HEADER_H
# define T_MINO_TYPES 19

# include "libft.h"
# include <fcntl.h>

#include <stdio.h>

typedef char t_field[256];

#define TMINO_SIZE 4
#define TMINO_STR_LEN 16
typedef char t_mino[16];

t_mino		g_tminos[T_MINO_TYPES];

//t_mino      g_tmino_buf;
//int			g_best_perimeter;
//t_field		g_best_field;
//int         g_best_rang;
//
int         g_field_size;
int         g_field_str_len;

///         main.c begins
int		    main(int argc, char **argv);
///         main.c ends


///         start.c begins
void        start(t_mino *array, int mino_num);
void        calculate_and_set_boundary(int minu_num);
void	    init_field(t_field field);
///         start.c ends


///         shift.c begins
void		shift_left(t_mino tmino);
void		shift_up(t_mino tmino);
void		shift_up_left(t_mino tmino);
///         shift.c ends


///         define_tetrimino.c begins
int		    count_chars(t_mino tmino, char c);
int		    ft_tmino_cmp(t_mino t1, t_mino t2);
void	    define_g_tminos(void);
int			define_tetrimino(t_mino tmino);
///         define_tetrimino.c ends


///         fit.c begins
int		    is_perimiter_empty(t_field field, int size);
void	    stack(t_field field, int index, t_mino mino);
int		    try_stack(t_field field, int index, t_mino mino);
int		    find_perimiter_size(t_field field);
int		    is_perimiter_empty(t_field field, int size);
void        delete_from_field(t_field field, int index, t_mino mino);
void        tmino_swap(t_mino t1, t_mino t2);
// aloha
int		rec_puzzle(t_field field, t_mino *tminos, int mino_num, int size);

int			get_index_by_num(int num, int size);
void		mino_to_letter(t_mino mino, int num);

//new one
void        rotate_array(t_mino *array, int num);
///         fit.c ends


///         print.c begins
void	    print_tmino_array(t_mino *array, int num);
void		print_tmino(t_mino tmino);
void	    print_field(t_field field, int	size);
void	    print_error(void);
void	    print_usage(void);
void		print_step(char *str);
///         print.c ends


///         read.c begins
int			read_newline(int fd);
int			read_tmino(int fd, t_mino tmino);
///         read.c ends

#endif
