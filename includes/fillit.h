/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:07:07 by basylbek          #+#    #+#             */
/*   Updated: 2019/10/21 18:45:17 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define INDEXES int i = 0; int y = 0; int x = 0;
# define LETTER char letter = 'A';
# define A (int [8]) {0,0,0,1,0,2,0,3}
# define B (int [8]) {0,0,1,0,2,0,3,0}
# define C (int [8]) {0,0,1,0,0,1,1,1}
# define D (int [8]) {0,0,0,1,0,2,1,2}
# define E (int [8]) {0,0,1,0,2,0,0,1}
# define F (int [8]) {0,0,1,0,1,1,1,2}
# define G (int [8]) {2,0,0,1,1,1,2,1}
# define H (int [8]) {1,0,1,1,0,2,1,2}
# define I (int [8]) {0,0,0,1,1,1,2,1}
# define J (int [8]) {0,0,1,0,0,1,0,2}
# define K (int [8]) {0,0,1,0,2,0,2,1}
# define L (int [8]) {1,0,0,1,1,1,2,1}
# define M (int [8]) {0,0,0,1,1,1,0,2}
# define N (int [8]) {0,0,1,0,2,0,1,1}
# define O (int [8]) {1,0,0,1,1,1,1,2}
# define P (int [8]) {1,0,2,0,0,1,1,1}
# define Q (int [8]) {0,0,0,1,1,1,1,2}
# define R (int [8]) {0,0,1,0,1,1,2,1}
# define S (int [8]) {1,0,0,1,1,1,0,2}
# define T int *f[] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S};
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct			s_tetrimino
{
	char				c;
	int					*indexes;
	struct s_tetrimino	*next;
}						t_tetrimino;

int						check(int fd, char **s);
char					*makestr(int fd);
void					create_buff(char *s, char *buff);
int						create_list(char *s, t_tetrimino **head);
void					delete_list(t_tetrimino **begin_list);
int						list_size(t_tetrimino *begin_list);
int						*align(int *arr, char c);
int						*create_array(char *buff);
int						check_array(int *arr);
void					fill_grid(char **grid, int *arr, char c);
void					free_grid(char **grid, int grid_size);
void					print_grid(char **grid, int grid_size);
char					**create_grid(int grid_size);
int						find_min_xy(int *arr, char c);
int						find_max_xy(int *arr, char c);
int						fillit(char **grid, t_tetrimino *head, int grid_size);
#endif
