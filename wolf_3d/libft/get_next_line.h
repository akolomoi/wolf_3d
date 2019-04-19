/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:39:26 by akolomoi          #+#    #+#             */
/*   Updated: 2018/11/03 14:39:27 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 64

typedef struct		s_file
{
	int				fd;
	struct s_file	*next;
	char			*buf;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
