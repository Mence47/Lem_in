/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:28:02 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/26 21:29:22 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

SDL_Color	*ft_generate_color(void)
{
	SDL_Color *color;

	color = (SDL_Color *)malloc(sizeof(SDL_Color));
	color->r = (Uint8)(rand() % 255);
	color->g = (Uint8)(rand() % 255);
	color->b = (Uint8)(rand() % 255);
	return (color);
}

void		ft_draw_circle(SDL_Renderer *r, t_node *room, SDL_Color *color)
{
	int dx;
	int dy;
	int i;
	int j;

	SDL_SetRenderDrawColor(r, color->r, color->g, color->b, color->a);
	i = 0;
	while (i < RADIUS * 2)
	{
		j = 0;
		while (j < RADIUS * 2)
		{
			dx = RADIUS - i;
			dy = RADIUS - j;
			if ((dx * dx + dy * dy) <= (RADIUS * RADIUS))
				SDL_RenderDrawPoint(r, room->coord.x + dx, room->coord.y + dy);
			j++;
		}
		i++;
	}
}

void		ft_draw_tag_rooms(SDL_Renderer *r, t_node *room, float theta)
{
	float	step;
	int		new_x;
	int		new_y;
	int		old_x;
	int		old_y;

	old_x = room->coord.x + RADIUS;
	old_y = room->coord.y;
	step = (float)((M_PI * 2) / 50);
	theta = 0;
	SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0x00);
	while (theta <= (M_PI * 2))
	{
		new_x = (int)(room->coord.x + (RADIUS * cos(theta)));
		new_y = (int)(room->coord.y - (RADIUS * sin(theta)));
		SDL_RenderDrawLine(r, old_x, old_y, new_x, new_y);
		old_x = new_x;
		old_y = new_y;
		theta += step;
	}
	new_x = (int)(room->coord.x + (RADIUS * cos(0)));
	new_y = (int)(room->coord.y - (RADIUS * sin(0)));
	SDL_RenderDrawLine(r, old_x, old_y, new_x, new_y);
}

void		ft_draw_circles(SDL_Renderer *r, t_graph *graph, SDL_Color *color)
{
	int	i;

	i = 0;
	while (i < (int)graph->count)
	{
		ft_draw_circle(r, graph->nodes[i], color);
		if (graph->nodes[i]->tag != REGULAR)
			ft_draw_tag_rooms(r, graph->nodes[i], 0);
		i++;
	}
}

void		ft_draw_edges(SDL_Renderer *r, t_edge *edges)
{
	t_edge *head;

	head = edges;
	while (head)
	{
		SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderDrawLine(r, head->start.x, head->start.y,
				head->end.x, head->end.y);
		head = head->next;
	}
}
