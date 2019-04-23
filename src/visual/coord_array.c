/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:12:29 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/27 20:12:45 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int					ft_abs(int num)
{
	if (num < 0)
		return ((-1) * num);
	return (num);
}

static int			ft_last_square(unsigned int num)
{
	int i;
	int res;

	i = 1;
	res = 0;
	while (i < (int)num)
	{
		if (i * i <= (int)num)
			res = i;
		i++;
	}
	return (res);
}

static t_ncoord		*ft_make_dot(int a, int b)
{
	t_ncoord	*new;

	new = (t_ncoord *)malloc(sizeof(t_ncoord));
	CHECK(new);
	new->tag = 0;
	new->coord.x = a;
	new->coord.y = b;
	return (new);
}

static t_ncoord		**ft_make_coordarr(int count, int step)
{
	t_ncoord	**new;
	int			i;
	int			a;
	int			b;

	new = (t_ncoord **)malloc(sizeof(t_ncoord *) * count);
	CHECK(new);
	i = 0;
	a = 0;
	b = 0;
	while (i < count)
	{
		new[i] = ft_make_dot(a, b);
		a += step;
		if (a > AREA_X)
		{
			a = 0;
			b += step;
		}
		i++;
	}
	return (new);
}

t_newcoord			*ft_init_coordarr(int nodes)
{
	t_newcoord	*new;
	int			step;

	new = (t_newcoord *)malloc(sizeof(t_newcoord));
	CHECK(new);
	step = ft_last_square((unsigned int)((AREA_X * AREA_Y) / nodes));
	new->count = nodes;
	new->coordarr = ft_make_coordarr(nodes, step);
	return (new);
}
