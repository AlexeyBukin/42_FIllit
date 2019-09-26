/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:05:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/25 21:06:35 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_HEADER_H
# define FILLIT_HEADER_H
# define T_MINO_TYPES 19

# include "libft.h"
# include <fcntl.h>

#define FIELD_SIZE 16
#define FIELD_STR_LEN 256
typedef char t_field[256];

#define TMINO_SIZE 4
#define TMINO_STR_LEN 16
typedef char t_mino[16];

int			define_tetrimino(t_mino tmino);

void		shift_left(t_mino tmino);
void		shift_up(t_mino tmino);
void		shift_up_left(t_mino tmino);


void	print_error(void);
void	print_usage(void);
void	print_field(t_field field, int	size);

void		print_tmino(t_mino tmino);
int			read_newline(int fd);
int			read_tmino(int fd, t_mino tmino);


void		define_g_tminos(void);

t_mino		g_tminos[T_MINO_TYPES];

int		is_perimiter_empty(t_field field, int size);
void	stack(t_field field, int index, t_mino mino);
int		try_stack(t_field field, int index, t_mino mino);

int		find_perimiter_size(t_field field);



////

void		print_step(char *str);
void		rec_puzzle(t_field field, t_mino *tminos, int mino_num);
int			get_index_by_num(int num, int size);
void		mino_to_letter(t_mino mino, int num);

void	init_field(t_field field);

#endif
