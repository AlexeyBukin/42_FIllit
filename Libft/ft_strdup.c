/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:57:56 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/07 17:58:33 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res != 0)
		return (ft_strcpy(res, s));
	return (0);
}
