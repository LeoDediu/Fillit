/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:25:59 by basylbek          #+#    #+#             */
/*   Updated: 2019/09/16 15:34:13 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr1;
	void			*ptr;
	size_t			i;

	i = 0;
	if (!(ptr1 = (void*)malloc(size)))
		return (NULL);
	while (i < size)
	{
		ptr1[i] = 0;
		i++;
	}
	ptr = (void*)ptr1;
	return (ptr);
}
