/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:22:16 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/15 13:52:14 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "../libft.h"
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi_test(char *str);
int		ft_strlen_test(char *str);
void	print_mem(void *p, size_t length);
void	print_mem_cmp(void *p1, void *p2, size_t length);
void	ft_print_list(t_list *list);

#endif
