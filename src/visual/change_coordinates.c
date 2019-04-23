/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:27:54 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/27 15:49:29 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	ft_make_shift(t_graph **graph, t_rect **rect, int sh_x, int sh_y)
{
	int i;

	i = 0;
	while (i < (int)(*graph)->count)
	{
		(*graph)->nodes[i]->coord.x += sh_x;
		(*graph)->nodes[i]->coord.y += sh_y;
		i++;
	}
	(*rect)->bottom.x += sh_x;
	(*rect)->bottom.y += sh_y;
	(*rect)->top.x += sh_x;
	(*rect)->top.y += sh_y;
}

static void	ft_zero_coord(t_graph **graph, t_rect **rect)
{
	int shift_x;
	int shift_y;

	shift_x = 0 - (*rect)->bottom.x;
	shift_y = 0 - (*rect)->bottom.y;
	ft_make_shift(graph, rect, shift_x, shift_y);
}

static void	ft_scale_coord(t_graph **graph, t_rect **rect)
{
	int max_x;
	int max_y;
	int scale;
	int i;

	max_x = (*rect)->top.x;
	max_y = (*rect)->top.y;
	if (max_x > max_y)
		scale = AREA_X / max_x;
	else
		scale = AREA_Y / max_y;
	i = 0;
	while (i < (int)(*graph)->count)
	{
		(*graph)->nodes[i]->coord.x *= scale;
		(*graph)->nodes[i]->coord.y *= scale;
		i++;
	}
	(*rect)->bottom.x *= scale;
	(*rect)->bottom.y *= scale;
	(*rect)->top.x *= scale;
	(*rect)->top.y *= scale;
	(*rect)->height *= scale;
	(*rect)->width *= scale;
}

static void	ft_center_coord(t_graph **graph, t_rect **rect)
{
	int shift_x;
	int shift_y;

	shift_x = SCR_CEN_X - ((*rect)->width / 2);
	shift_y = SCR_CEN_Y - ((*rect)->height / 2);
	ft_make_shift(graph, rect, shift_x, shift_y);
}

void		ft_change_coord(t_graph **graph)
{
	t_rect *rect;

	rect = ft_find_rectangle(graph, 0);
	ft_zero_coord(graph, &rect);
	ft_scale_coord(graph, &rect);
	if (is_bigger_than_map(*graph))
		ft_remake_coord(graph, &rect);
	ft_center_coord(graph, &rect);
	free(rect);
	rect = NULL;
}
