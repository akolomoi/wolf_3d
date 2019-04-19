/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:43:18 by akolomoi          #+#    #+#             */
/*   Updated: 2018/11/03 14:43:19 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file		*get_file_fd(const int fd, t_file **f)
{
	t_file *cur;

	if (!(*f))
	{
		if (!((*f) = (t_file*)malloc(sizeof(t_file))))
			return (NULL);
		(*f)->fd = fd;
		(*f)->buf = NULL;
		(*f)->next = NULL;
		return (*f);
	}
	cur = (*f);
	while (cur->next)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	if (cur->fd == fd)
		return (cur);
	cur->next = get_file_fd(fd, &cur->next);
	return (cur->next);
}

static void	process(t_file **c, char **line, char *buf, char *lf)
{
	char	*sub;

	sub = ft_strsub(buf, 0, lf - buf);
	*line = ft_strjoin(*line, sub);
	free(sub);
	if (*(lf + 1))
		(*c)->buf = ft_strdup((lf + 1));
	else
		ft_strdel(&(*c)->buf);
}

static int	process_file_buf(t_file **c, char **line)
{
	char	*sub;
	char	*lf;
	char	*buf;

	if (!(*c)->buf)
		return (0);
	buf = (*c)->buf;
	if ((lf = ft_strchr(buf, '\n')))
	{
		sub = ft_strsub(buf, 0, lf - buf);
		*line = ft_strjoin(*line, sub);
		free(sub);
		if (*(lf + 1))
			(*c)->buf = ft_strdup((lf + 1));
		else
			ft_strdel(&(*c)->buf);
		return (1);
	}
	*line = ft_strdup(buf);
	ft_strdel(&(*c)->buf);
	return (0);
}

static int	dark_magic(int fd, char **line, t_file **current)
{
	char	buf[BUFF_SIZE + 1];
	char	*lf;
	int		i;

	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		if (i < 0)
			return (-1);
		buf[i] = '\0';
		if (!(lf = ft_strchr(buf, '\n')))
			*line = ft_strjoin(*line, buf);
		else
		{
			process(current, line, buf, lf);
			break ;
		}
	}
	if (!*line && !i)
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_file	*lists;
	t_file			*current;
	char			buf[1];

	if ((current = get_file_fd(fd, &lists)) == NULL || fd < 0 || line == NULL
	|| BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	*line = NULL;
	if (process_file_buf(&current, line))
		return (1);
	return (dark_magic(fd, line, &current));
}
