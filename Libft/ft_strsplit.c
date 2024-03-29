/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:14:14 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/22 13:36:55 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sub_len(const char *s, size_t len, int i, char c)
{
	if (ft_memchr((char*)&s[i], c, len - i) == 0)
	{
		return (len - i);
	}
	else
	{
		return ((char*)(ft_memchr((char*)&s[i], c, len - i)) - &s[i]);
	}
}

static void		ft_free_arr(char ***input)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (input == 0)
		return ;
	arr = *input;
	if (arr == 0)
		return ;
	while (arr[i] != 0)
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
	free(arr);
	arr = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	len;
	char	**res;
	int		sl;
	int		j;
	int		i;

	if (s == 0)
		return (0);
	len = ft_strlen(s);
	if ((res = (char**)malloc(sizeof(char*) * (ft_word_count(s, c) + 1))) == 0)
		return (0);
	i = 0;
	j = -1;
	while (++j < ft_word_count(s, c))
	{
		while (s[i] == c)
			i++;
		sl = sub_len(s, len, i, c);
		(res[j] = ft_strsub(s, i, sl)) == 0 ? ft_free_arr(&res) : 777;
		if (res[j] == 0)
			return (0);
		i = i + sl;
	}
	res[j] = 0;
	return (res);
}
