/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:18:00 by basylbek          #+#    #+#             */
/*   Updated: 2019/10/21 15:32:21 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		xy_shift(int *arr, int grid_size, char c)
{
	int arr_max;

	arr_max = find_max_xy(arr, c);
	if (arr_max >= grid_size)
		return (1);
	return (0);
}

int		is_safe(char **grid, int *arr, int grid_size)
{
	INDEXES;
	if (xy_shift(arr, grid_size, 'x') || xy_shift(arr, grid_size, 'y'))
		return (0);
	while (i < 8)
	{
		y = arr[i];
		x = arr[i + 1];
		if (grid[x][y] != '.')
			return (0);
		i = i + 2;
	}
	return (1);
}

void	increase_index(int *arr, char c)
{
	int i;

	i = (c == 'x') ? 0 : 1;
	while (i < 8)
	{
		arr[i] = arr[i] + 1;
		i = i + 2;
	}
}

int		find_location(char **grid, int *arr, int grid_size)
{
	if (is_safe(grid, arr, grid_size))
		return (1);
	while (1)
	{
		increase_index(arr, 'x');
		if (xy_shift(arr, grid_size, 'x'))
		{
			align(arr, 'x');
			increase_index(arr, 'y');
		}
		if (xy_shift(arr, grid_size, 'y'))
			return (0);
		if (is_safe(grid, arr, grid_size))
			return (1);
	}
}

int		fillit(char **grid, t_tetrimino *head, int grid_size)
{
	if (!head)
		return (1);
	while (find_location(grid, head->indexes, grid_size))
	{
		fill_grid(grid, head->indexes, head->c);
		if (fillit(grid, head->next, grid_size))
			return (1);
		else
		{
			fill_grid(grid, head->indexes, '.');
			increase_index(head->indexes, 'x');
		}
	}
	align(head->indexes, 'x');
	align(head->indexes, 'y');
	return (0);
}
