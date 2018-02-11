/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:00:59 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/08 16:22:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line		*new_struct_gnl(int fd)
{
	t_line *struct_new;

	struct_new = (t_line*)malloc(sizeof(t_line));
	if (!struct_new)
	{
		free(struct_new);
		return (NULL);
	}
	struct_new->fd = fd;
	struct_new->buff_fd = ft_strnew(0);
	struct_new->next = NULL;
	return (struct_new);
}

t_line		*next_struct_gnl(t_line *gnl, int fd)
{
	t_line	*gnl_fd;

	gnl_fd = gnl;
	while (gnl_fd)
	{
		if (gnl_fd->fd == fd)
			break ;
		if (gnl_fd->next == NULL && gnl_fd->fd != fd)
		{
			gnl_fd->next = new_struct_gnl(fd);
			gnl_fd = gnl_fd->next;
			break ;
		}
		gnl_fd = gnl_fd->next;
	}
	return (gnl_fd);
}

char		*ft_read(int fd, char *buff_fd, int *symbol_fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*buff;

	ft_bzero(buf, BUFF_SIZE + 1);
	*symbol_fd = read(fd, buf, BUFF_SIZE);
	buf[*symbol_fd] = '\0';
	buff = ft_strjoin(buff_fd, buf);
	ft_strdel(&buff_fd);
	return (buff);
}

int			ft_status(t_line *gnl_fd, int fd, char **line)
{
	int		symbol_fd;
	char	*get_line;

	symbol_fd = 1;
	while (symbol_fd > 0)
	{
		gnl_fd->buff_fd = ft_read(fd, gnl_fd->buff_fd, &symbol_fd);
		get_line = ft_strchr(gnl_fd->buff_fd, '\n');
		if (get_line != NULL)
		{
			*get_line = '\0';
			*line = ft_strdup(gnl_fd->buff_fd);
			ft_memmove(gnl_fd->buff_fd, get_line + 1,
					ft_strlen(get_line + 1) + 1);
			return (1);
		}
		else if (ft_strlen(gnl_fd->buff_fd) && symbol_fd == 0)
		{
			*line = ft_strdup(gnl_fd->buff_fd);
			ft_bzero(gnl_fd->buff_fd, ft_strlen(gnl_fd->buff_fd));
			return (1);
		}
	}
	return (symbol_fd);
}

int			get_next_line(const int fd, char **line)
{
	static t_line	*gnl;
	t_line			*gnl_fd;

	if (fd < 0 || BUFF_SIZE <= 0 || BUFF_SIZE > 65534 || !line)
		return (-1);
	if (!gnl)
		gnl = new_struct_gnl(fd);
	gnl_fd = next_struct_gnl(gnl, fd);
	return (ft_status(gnl_fd, fd, line));
}
