/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:38:00 by basylbek          #+#    #+#             */
/*   Updated: 2019/10/21 17:26:23 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

LETTER;

static t_tetrimino	*create_elem(int *arr)
{
	t_tetrimino	*element;

	if (!(element = (t_tetrimino*)malloc(sizeof(t_tetrimino))))
		return (NULL);
	element->c = letter;
	letter++;
	element->indexes = arr;
	element->next = NULL;
	return (element);
}

static void			list_push_back(t_tetrimino **begin_list, int *arr)
{
	t_tetrimino *tmp;

	tmp = *begin_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_elem(arr);
	}
	else
		*begin_list = create_elem(arr);
}

int					create_list(char *s, t_tetrimino **begin_list)
{
	int		*arr;
	char	buff[ft_strlen(s)];
	int		x;
	int		i;

	x = 0;
	create_buff(s, buff);
	i = ft_strlen(buff);
	while (x < i)
	{
		arr = create_array(ft_strsub(buff, x, 16));
		if (check_array(arr))
			return (0);
		list_push_back(begin_list, arr);
		x = x + 16;
	}
	return (1);
}

void				delete_list(t_tetrimino **begin_list)
{
	t_tetrimino *to_free;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list)
	{
		to_free = *begin_list;
		*begin_list = (*begin_list)->next;
		free(to_free->indexes);
		free(to_free);
	}
	*begin_list = NULL;
}

int					list_size(t_tetrimino *begin_list)
{
	t_tetrimino	*tmp;
	int			count;

	count = 0;
	if (!begin_list)
		return (count);
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		++count;
	}
	return (count);
}
