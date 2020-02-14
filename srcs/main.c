/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:07:59 by basylbek          #+#    #+#             */
/*   Updated: 2019/10/21 16:20:15 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_max_xy(int *arr, char c)
{
	int max;
	int i;

	i = (c == 'x') ? 0 : 1;
	max = arr[i];
	while (i < 8)
	{
		if (max < arr[i])
			max = arr[i];
		i = i + 2;
	}
	return (max);
}

int		find_min_xy(int *arr, char c)
{
	int min;
	int i;

	i = (c == 'x') ? 0 : 1;
	min = arr[i];
	while (i < 8)
	{
		if (min > arr[i])
			min = arr[i];
		i = i + 2;
	}
	return (min);
}

int		ft_sqrt(int c)
{
	int i;

	i = 1;
	while ((i * i) < c)
		i++;
	return (i);
}

int		handle_grid(char *s)
{
	int				grid_size;
	char			**grid;
	t_tetrimino		*begin_list;

	begin_list = NULL;
	if (!create_list(s, &begin_list))
		return (1);
	grid_size = ft_sqrt(list_size(begin_list) * 4);
	grid = create_grid(grid_size);
	while (!fillit(grid, begin_list, grid_size))
	{
		free_grid(grid, grid_size);
		grid_size++;
		grid = create_grid(grid_size);
	}
	print_grid(grid, grid_size);
	free_grid(grid, grid_size);
	delete_list(&begin_list);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (check(fd, &line) || handle_grid(line))
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
		ft_putstr("usage: give me one file");
	return (0);
}
