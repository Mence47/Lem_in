/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_for_visual.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:36:43 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/02 21:28:55 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			ft_delete_text_color(t_text **text, SDL_Color **color)
{
	SDL_FreeSurface((*text)->sdl_surface);
	(*text)->sdl_surface = NULL;
	SDL_DestroyTexture((*text)->message);
	((*text)->message) = NULL;
	free(*color);
	*color = NULL;
	free(*text);
	*text = NULL;
}

void			ft_delete_text(t_text **text)
{
	SDL_FreeSurface((*text)->sdl_surface);
	(*text)->sdl_surface = NULL;
	SDL_DestroyTexture((*text)->message);
	((*text)->message) = NULL;
	free(*text);
	*text = NULL;
}

void			ft_delete_visual_kit(t_vkit **kit)
{
	TTF_CloseFont((*kit)->small_font);
	(*kit)->small_font = NULL;
	TTF_CloseFont((*kit)->large_font);
	(*kit)->large_font = NULL;
	SDL_DestroyRenderer((*kit)->sdl_renderer);
	(*kit)->sdl_renderer = NULL;
	SDL_DestroyWindow((*kit)->sdl_window);
	(*kit)->sdl_window = NULL;
}

static void		ft_delete_edges(t_edge **edges)
{
	t_edge *tmp;
	t_edge *del;

	if (*edges == NULL)
		return ;
	tmp = *edges;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*edges = NULL;
}

void			ft_delete_comp(t_comp **comp)
{
	if (*comp == NULL)
		return ;
	ft_delete_graph(&((*comp)->graph));
	ft_delete_edges(&((*comp)->edges));
	ft_delete_antarr(&((*comp)->antarr));
	ft_delete_set(&((*comp)->set));
	free(*comp);
	*comp = NULL;
}
