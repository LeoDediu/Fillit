/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:37:15 by basylbek          #+#    #+#             */
/*   Updated: 2019/10/21 17:27:14 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_figures(char *s)
{
	int i;
	int num;
	int dot;

	i = 0;
	num = 0;
	dot = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
			dot++;
		if ((s[i] == '\n') && (s[i + 1] == '\n'))
		{
			num++;
			if (dot != 12)
				return (0);
			dot = 0;
		}
		i++;
	}
	return (num + 1);
}

int		count_char(char *s, char c)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			num++;
		i++;
	}
	return (num);
}

char	*makestr(int fd)
{
	int		ret;
	int		i;
	char	c;
	char	*s;

	i = 0;
	s = (char*)malloc(sizeof(char) * 550);
	while ((ret = read(fd, &c, 1)) > 0)
		s[i++] = c;
	s[i] = '\0';
	if (ret < 0)
		return (NULL);
	return (s);
}

void	create_buff(char *s, char *buff)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != '\n')
			buff[i++] = *s;
		s++;
	}
	buff[i] = '\0';
}

int		check(int fd, char **s)
{
	int i;
	int figcount;
	int hashcount;
	int dotcount;
	int newlcount;

	*s = makestr(fd);
	figcount = count_figures(*s);
	hashcount = count_char(*s, '#');
	dotcount = count_char(*s, '.');
	newlcount = count_char(*s, '\n');
	i = 0;
	while ((*s)[i] != '\0')
	{
		if ((*s)[i] != '#' && (*s)[i] != '.' && (*s)[i] != '\n')
			return (1);
		i++;
	}
	if ((figcount * 4 == hashcount) && (figcount * 12 == dotcount) &&
			(newlcount == hashcount + figcount - 1))
		return (0);
	return (1);
}
