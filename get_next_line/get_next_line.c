/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:47:16 by bglinda           #+#    #+#             */
/*   Updated: 2019/05/06 14:47:16 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				save(char *str, char **ram)
{
	char			*a;

	if (*str)
	{
		a = *ram;
		*ram = ft_strdup(str);
		free(a);
	}
}

char				*joinfree(char const *s1, char const *s2)
{
	char			*res;

	res = ft_strjoin(s1, s2);
	if (res)
		free((char *)s1);
	return (res);
}

int					uram(char **line, char **ram, char **end)
{
	if (*ram && **ram)
	{
		if ((*end = ft_strchr(*ram, '\n')))
		{
			**end = '\0';
			*line = joinfree(*line, *ram);
			save(++(*end), ram);
			if (ft_strequ(*ram, *line))
				ft_strclr(*ram);
			return (1);
		}
		else
			*line = joinfree(*line, *ram);
		if (!ft_strchr(*ram, '\n'))
			ft_strclr(*ram);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			*end;
	char			buf[BUFF_SIZE + 1];
	static	char	*ram[OPEN_MAX];

	if (fd < 0 || !line || (fd > OPEN_MAX))
		return (-1);
	*line = ft_strnew(0);
	if (uram(line, &ram[fd], &end))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((end = ft_strchr(buf, '\n')))
		{
			*end = '\0';
			save(++end, &ram[fd]);
			*line = joinfree(*line, buf);
			return (1);
		}
		*line = joinfree(*line, buf);
	}
	if (**line && ret == 0)
		return (1);
	return (ret);
}
