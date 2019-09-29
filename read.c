/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:10:26 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/26 18:10:26 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit_header.h"

int		read_newline(int fd)
{
    int 	res;
    char	n;

    res = read(fd, &n, 1);
    if (res == 1 && n == '\n')
        return (1);
    return (0);
}

//TODO clean read function, with loop and reading newlines

int		read_tmino(int fd, t_mino tmino)
{
    int read_bytes = 0;
    char	buffer[20];

    read_bytes = read(fd, buffer, 20);
    if (read_bytes != 20)
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
