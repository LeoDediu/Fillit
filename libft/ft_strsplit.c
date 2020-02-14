/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:59:15 by basylbek          #+#    #+#             */
/*   Updated: 2019/09/22 14:48:17 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		len;
	int		i;
	int		num_words;

	i = 0;
	if (!s || !c)
		return (NULL);
	num_words = ft_count_word(s, c);
	if (!(str = (char**)malloc(sizeof(*str) * (num_words + 1))))
		return (NULL);
	while (num_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		len = ft_strlen_c(s, c);
		str[i] = ft_strsub(s, 0, len);
		if (str[i] == '\0')
			return (NULL);
		s = s + ft_strlen_c(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
