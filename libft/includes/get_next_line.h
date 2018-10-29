/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:21:16 by iradchen          #+#    #+#             */
/*   Updated: 2018/01/10 13:34:43 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8096
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

# define ERR -1
# define TRUE 1
# define FALSE 0
# define SUCS TRUE
# define END FALSE
# define NOSTATUS 404
# define ISSTATUS(x) (x != NOSTATUS)
# define ISINVALID(x) (x < 0)
# define ISWORD(x) (x ? SUCS : END)
# define ISADD(flag, add) (flag ? add : 0)
# define ISREM(rem) (rem ? ft_strdup(rem) : rem)

typedef struct	s_line
{
	t_list	*words;
	size_t	words_len;
	char	*old_rem;
	char	*rem;
	int		fd;
}				t_line;

#endif
