/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:26:30 by basylbek          #+#    #+#             */
/*   Updated: 2019/10/21 16:16:30 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_grid(int grid_size)
{
	char	**grid;
	int		x;
	int		y;

	grid = (char**)malloc(sizeof(grid) * grid_size);
	x = 0;
	while (x < grid_size)
	{
		grid[x] = (char*)malloc(sizeof(*grid) * grid_size);
		x++;
	}
	x = 0;
	while (x < grid_size)
	{
		y = 0;
		while (y < grid_size)
		{
			grid[x][y] = '.';
			y++;
		}
		x++;
	}
	return (grid);
}

void	print_grid(char **grid, int grid_size)
{
	int x;
	int y;

	x = 0;
	while (x < grid_size)
	{
		y = 0;
		while (y < grid_size)
		{
			ft_putchar(grid[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

void	free_grid(char **grid, int grid_size)
{
	int i;

	i = 0;
	while (i < grid_size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	fill_grid(char **grid, int *arr, char c)
{
	INDEXES;
	while (i < 8)
	{
		y = arr[i];
		x = arr[i + 1];
		grid[x][y] = c;
		i = i + 2;
	}
}
