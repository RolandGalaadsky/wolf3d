/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:22:56 by iradchen          #+#    #+#             */
/*   Updated: 2018/01/10 13:39:35 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		set_rem(t_line *my_line, char **line)
{
	int		diff;
	char	*rem;
	t_list	*new_word;
	size_t	word_size;

	(my_line->rem)++;
	rem = ft_strchr(my_line->rem, '\n');
	if (rem)
	{
		diff = rem - my_line->rem;
		*line = ft_strnew(diff);
		ft_strncpy(*line, my_line->rem, diff);
		my_line->rem = ft_strdup(my_line->rem + diff);
		return (SUCS);
	}
	else
	{
		word_size = ft_strlen(my_line->rem);
		my_line->words_len += word_size;
		new_word = ft_lstnew(my_line->rem, word_size);
		ft_lstadd(&(my_line->words), new_word);
	}
	return (NOSTATUS);
}

int		set_line(t_line *my_line, char *data, char **line, int bites)
{
	int		diff;
	t_list	*next;
	int		status;
	char	*content;
	size_t	content_size;

	diff = my_line->rem - data;
	*line = ft_strnew(my_line->words_len + ISADD(my_line->rem, diff));
	ft_lstrev(&(my_line->words));
	status = ISWORD(my_line->words);
	while (my_line->words)
	{
		content = my_line->words->content;
		content_size = my_line->words->content_size;
		ft_strncat(*line, content, content_size);
		next = my_line->words->next;
		ft_memdel((void **)&(my_line->words->content));
		ft_memdel((void **)&(my_line->words));
		my_line->words = next;
	}
	ft_strncat(*line, data, diff);
	my_line->rem = ISREM(my_line->rem);
	if (!bites)
		return (status);
	return (SUCS);
}

int		get_line(t_line *my_line, char **line)
{
	char	data[BUFF_SIZE + 1];
	int		bites;
	int		status;

	status = NOSTATUS;
	if ((my_line->old_rem = my_line->rem))
		status = set_rem(my_line, line);
	ft_strdel(&(my_line->old_rem));
	while (!ISSTATUS(status))
	{
		ft_bzero(data, BUFF_SIZE + 1);
		bites = read(my_line->fd, data, BUFF_SIZE);
		if (ISINVALID(bites))
			status = ERR;
		else if ((my_line->rem = ft_strchr(data, '\n')) || !bites)
			status = set_line(my_line, data, line, bites);
		else
		{
			my_line->words_len += bites;
			ft_lstadd(&(my_line->words), ft_lstnew(data, bites));
		}
	}
	if (status == ERR || status == END)
		ft_strdel(&(my_line->rem));
	return (status);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lines;
	t_list			*temp;
	t_line			*my_line;

	if (!line || ISINVALID(fd) || BUFF_SIZE <= 0)
		return (ERR);
	my_line = NULL;
	temp = lines;
	while (temp)
	{
		my_line = (t_line *)temp->content;
		if (my_line->fd == fd)
			return (get_line(my_line, line));
		else
			my_line = NULL;
		temp = temp->next;
	}
	my_line = (t_line *)ft_memalloc(sizeof(t_line));
	my_line->fd = fd;
	ft_lstadd(&lines, ft_lstnew(my_line, sizeof(t_line)));
	ft_memdel((void **)&my_line);
	return (get_line(lines->content, line));
}
