/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:27:43 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/26 21:29:22 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

SDL_Color		*ft_make_color(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color *new;

	new = (SDL_Color *)malloc(sizeof(SDL_Color));
	CHECK(new);
	new->r = r;
	new->g = g;
	new->b = b;
	new->a = 255;
	return (new);
}

t_text			*ft_empty_text(void)
{
	t_text *new;

	new = (t_text *)malloc(sizeof(t_text));
	CHECK(new);
	new->height = 0;
	new->width = 0;
	return (new);
}

static t_rect	*ft_create_rectangle(int min_x, int max_x, int min_y, int max_y)
{
	t_rect	*rect;

	rect = (t_rect *)malloc(sizeof(t_rect));
	CHECK(rect);
	rect->bottom.x = min_x;
	rect->bottom.y = min_y;
	rect->top.x = max_x;
	rect->top.y = max_y;
	rect->height = max_y - min_y;
	rect->width = max_x - min_x;
	return (rect);
}

t_rect			*ft_find_rectangle(t_graph **graph, int i)
{
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
	t_rect	*rect;

	min_x = (*graph)->nodes[i]->coord.x;
	min_y = (*graph)->nodes[i]->coord.y;
	max_x = (*graph)->nodes[i]->coord.x;
	max_y = (*graph)->nodes[i]->coord.y;
	i++;
	while (i < (int)(*graph)->count)
	{
		if ((*graph)->nodes[i]->coord.x < min_x)
			min_x = (*graph)->nodes[i]->coord.x;
		if ((*graph)->nodes[i]->coord.y < min_y)
			min_y = (*graph)->nodes[i]->coord.y;
		if ((*graph)->nodes[i]->coord.x > max_x)
			max_x = (*graph)->nodes[i]->coord.x;
		if ((*graph)->nodes[i]->coord.y > max_y)
			max_y = (*graph)->nodes[i]->coord.y;
		i++;
	}
	rect = ft_create_rectangle(min_x, max_x, min_y, max_y);
	return (rect);
}
