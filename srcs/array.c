/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:36:50 by basylbek          #+#    #+#             */
/*   Updated: 2019/10/21 18:44:41 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*align(int *arr, char c)
{
	int smallest;
	int i;

	smallest = find_min_xy(arr, c);
	i = (c == 'x') ? 0 : 1;
	while (i < 8)
	{
		arr[i] = arr[i] - smallest;
		i = i + 2;
	}
	return (arr);
}

int			*create_array(char *buff)
{
	int			*arr;

	arr = (int*)malloc(sizeof(int) * 8);
	INDEXES;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (buff[y * 4 + x] == '#')
			{
				arr[i] = x;
				arr[i + 1] = y;
				i = i + 2;
			}
			x++;
		}
		y++;
	}
	align(arr, 'x');
	align(arr, 'y');
	return (arr);
}

int			check_arr(int *arr, int *arr2)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (arr[i] != arr2[i])
			return (0);
		i++;
	}
	return (1);
}

int			check_array(int *arr)
{
	int i;

	T;
	i = 0;
	while (i < 19)
	{
		if (check_arr(arr, f[i++]))
			return (0);
	}
	return (1);
}
