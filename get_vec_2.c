/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:35:23 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 18:35:25 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

double	*get_vec_2(double x, double y)
{
	double	*vec_2;

	vec_2 = (double *)ft_memalloc(VEC_2_SIZE);
	check_malloc((void *)vec_2);
	vec_2[X] = x;
	vec_2[Y] = y;
	return (vec_2);
}
