/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:29:11 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/28 20:23:43 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			ft_render_corner_text(t_vkit *kit)
{
	SDL_Color	*color;
	t_text		*text;
	int			ret;
	char		*str;

	str = ft_strdup("Ants left:");
	color = ft_make_color(0, 0, 0);
	text = ft_empty_text();
	text->sdl_rect.x = 10;
	text->sdl_rect.y = 10;
	ret = TTF_SizeText(kit->large_font, str, &(text->width), &(text->height));
	text->sdl_rect.w = text->width;
	text->sdl_rect.h = text->height;
	text->sdl_surface = TTF_RenderText_Solid(kit->large_font, str, *color);
	text->message = SDL_CreateTextureFromSurface(kit->sdl_renderer,
												text->sdl_surface);
	SDL_RenderCopy(kit->sdl_renderer, text->message, NULL, &(text->sdl_rect));
	ft_delete_text_color(&text, &color);
	ft_strdel(&str);
}

void			ft_render_text_ants(t_vkit *kit, int number)
{
	SDL_Color	*color;
	t_text		*text;
	int			ret;
	char		*str;

	color = ft_make_color(0, 0, 0);
	text = ft_empty_text();
	text->sdl_rect.x = 200;
	text->sdl_rect.y = 10;
	str = ft_itoa(number);
	ret = TTF_SizeText(kit->large_font, str, &(text->width), &(text->height));
	text->sdl_rect.w = text->width;
	text->sdl_rect.h = text->height;
	text->sdl_surface = TTF_RenderText_Solid(kit->large_font, str, *color);
	text->message = SDL_CreateTextureFromSurface(kit->sdl_renderer,
												text->sdl_surface);
	SDL_RenderCopy(kit->sdl_renderer, text->message, NULL, &(text->sdl_rect));
	ft_delete_text_color(&text, &color);
}

void			ft_show_ticks(SDL_Renderer *r, t_set **set, int flag)
{
	int	j;

	j = 0;
	if (flag < (int)(*set)->count)
	{
		while (j < (int)(*set)->ticks[flag]->count)
		{
			ft_draw_circle(r, (*set)->ticks[flag]->antroooms[j]->room,
						(*set)->ticks[flag]->antroooms[j]->ant->color);
			j++;
		}
	}
}

static void		ft_render_one_room(t_vkit *kit, t_graph *graph,
									int i, SDL_Color *color)
{
	t_text		*text;
	int			ret;

	text = ft_empty_text();
	text->sdl_rect.x = graph->nodes[i]->coord.x - RADIUS;
	text->sdl_rect.y = graph->nodes[i]->coord.y + RADIUS + 5;
	ret = TTF_SizeText(kit->small_font, graph->nodes[i]->name,
						&(text->width), &(text->height));
	text->sdl_rect.w = text->width;
	text->sdl_rect.h = text->height;
	text->sdl_surface = TTF_RenderText_Solid(kit->small_font,
										graph->nodes[i]->name, *color);
	text->message = SDL_CreateTextureFromSurface(kit->sdl_renderer,
												text->sdl_surface);
	SDL_RenderCopy(kit->sdl_renderer, text->message, NULL,
					&(text->sdl_rect));
	ft_delete_text(&text);
}

void			ft_render_room_names(t_vkit *kit, t_graph *graph)
{
	SDL_Color	*color;
	int			i;

	i = 0;
	color = ft_make_color(0, 0, 0);
	while (i < (int)graph->count)
	{
		ft_render_one_room(kit, graph, i, color);
		i++;
	}
	free(color);
	color = NULL;
}
