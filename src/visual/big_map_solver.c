/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:09:31 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/27 20:09:42 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static t_point		ft_choose_coord(t_newcoord **arr, int i)
{
	while ((*arr)->coordarr[i]->tag == 1)
		i++;
	(*arr)->coordarr[i]->tag = 1;
	return ((*arr)->coordarr[i]->coord);
}

static void			ft_change_rect(t_rect **rect, int min_max[4])
{
	(*rect)->bottom.x = min_max[0];
	(*rect)->bottom.y = min_max[1];
	(*rect)->top.x = min_max[2];
	(*rect)->top.y = min_max[3];
	(*rect)->height = min_max[3] - min_max[1];
	(*rect)->width = min_max[2] - min_max[0];
}

static void			ft_remake_rect(t_graph *graph, t_rect **rect, int i)
{
	int	min_max[4];

	min_max[0] = graph->nodes[i]->coord.x;
	min_max[1] = graph->nodes[i]->coord.y;
	min_max[2] = graph->nodes[i]->coord.x;
	min_max[3] = graph->nodes[i]->coord.y;
	i++;
	while (i < (int)graph->count)
	{
		if (graph->nodes[i]->coord.x < min_max[0])
			min_max[0] = graph->nodes[i]->coord.x;
		if (graph->nodes[i]->coord.y < min_max[1])
			min_max[1] = graph->nodes[i]->coord.y;
		if (graph->nodes[i]->coord.x > min_max[2])
			min_max[2] = graph->nodes[i]->coord.x;
		if (graph->nodes[i]->coord.y > min_max[3])
			min_max[3] = graph->nodes[i]->coord.y;
		i++;
	}
	ft_change_rect(rect, min_max);
}

void				ft_remake_coord(t_graph **graph, t_rect **rect)
{
	int			i;
	t_newcoord	*arr;

	i = 0;
	arr = ft_init_coordarr((*graph)->count);
	while (i < (int)(*graph)->count)
	{
		(*graph)->nodes[i]->coord = ft_choose_coord(&arr, i);
		i++;
	}
	ft_remake_rect(*graph, rect, 0);
	ft_delete_newcoord(&arr);
}

t_bool				is_bigger_than_map(t_graph *graph)
{
	int i;
	int j;

	i = 0;
	while (i < (int)graph->count)
	{
		j = 0;
		while (j < (int)graph->count)
		{
			if (i != j)
			{
				if ((ft_abs(graph->nodes[i]->coord.x -
				graph->nodes[j]->coord.x) < STEP) &&
				(ft_abs(graph->nodes[i]->coord.y -
				graph->nodes[j]->coord.y) < STEP))
					return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
