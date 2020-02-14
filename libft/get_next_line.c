/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:45:11 by basylbek          #+#    #+#             */
/*   Updated: 2019/10/18 13:29:21 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	assign(char **str, char **line, int ret)
{
	int		len;
	char	*tmp;

	if (ret == 0 && *str == NULL)
		return (0);
	else
	{
		len = ft_strlen_c(*str, '\n');
		if ((*str)[len] == '\n')
		{
			*line = ft_strsub(*str, 0, len);
			tmp = ft_strdup(&((*str)[len + 1]));
			free(*str);
			*str = tmp;
			if ((*str)[0] == '\0')
				ft_strdel(str);
		}
		else
		{
			*line = ft_strdup(*str);
			ft_strdel(str);
		}
		return (1);
	}
}

int			get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static	char	*str[1000];
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (ret < 0) ? -1 : (assign(&(str[fd]), line, ret));
}
