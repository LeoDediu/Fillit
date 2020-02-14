/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:01:58 by basylbek          #+#    #+#             */
/*   Updated: 2019/09/24 21:58:49 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp)
	{
		if (!content)
		{
			tmp->content_size = 0;
			tmp->content = NULL;
		}
		else
		{
			if (!(tmp->content = malloc(content_size)))
				return (NULL);
			tmp->content_size = content_size;
			ft_memcpy(tmp->content, content, content_size);
		}
		tmp->next = NULL;
	}
	return (tmp);
}
