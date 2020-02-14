/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:47:55 by basylbek          #+#    #+#             */
/*   Updated: 2019/09/22 15:50:19 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	num;

	num = n;
	i = ft_numlen(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		num = num * (-1);
		str[0] = '-';
	}
	str[i] = '\0';
	while (num)
	{
		str[--i] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
