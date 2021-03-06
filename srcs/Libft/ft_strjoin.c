/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:32:01 by abello-r          #+#    #+#             */
/*   Updated: 2021/08/02 14:01:27 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	size_t	c1;
	size_t	c2;
	size_t	i;

	i = 0;
	c2 = -1;
	c1 = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(x))
		return (NULL);
	while (++c1 != ft_strlen(s1))
	{
		x[i] = s1[c1];
		++i;
	}
	while (++c2 != ft_strlen(s2))
	{
		x[i] = s2[c2];
		++i;
	}
	x[i] = '\0';
	return (x);
}
