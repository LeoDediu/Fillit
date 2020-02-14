/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:01:29 by basylbek          #+#    #+#             */
/*   Updated: 2019/09/21 16:06:05 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if (!(tmp = (char*)malloc(sizeof(tmp) *
		(ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	i = 0;
	while (*s1 && s1)
	{
		tmp[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 && s2)
	{
		tmp[i] = *s2;
		s2++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
