/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:29:17 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/02 22:50:20 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	ft_print_error(int type, t_vkit **kit)
{
	if (type == 0 || type == 1 || type == 2)
		ft_putendl(SDL_GetError());
	if (type == 3 || type == 4 || type == 5)
		ft_putendl(TTF_GetError());
	if (type == 5)
	{
		TTF_CloseFont((*kit)->small_font);
		(*kit)->small_font = NULL;
	}
	if (type >= 4)
		TTF_Quit();
	if (type >= 3)
	{
		SDL_DestroyRenderer((*kit)->sdl_renderer);
		(*kit)->sdl_renderer = NULL;
	}
	if (type >= 2)
	{
		SDL_DestroyWindow((*kit)->sdl_window);
		(*kit)->sdl_window = NULL;
	}
	if (type >= 1)
		SDL_Quit();
}

t_bool		ft_ttf_init(t_vkit **kit)
{
	if (TTF_Init() == -1)
	{
		ft_print_error(3, kit);
		return (false);
	}
	else
	{
		(*kit)->small_font = TTF_OpenFont(FONT, 24);
		if (!(*kit)->small_font)
		{
			ft_print_error(4, kit);
			return (false);
		}
		else
		{
			(*kit)->large_font = TTF_OpenFont(FONT, 36);
			if (!(*kit)->large_font)
			{
				ft_print_error(5, kit);
				return (false);
			}
		}
	}
	return (true);
}

t_bool		ft_sdl_init(t_vkit **kit)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_print_error(0, kit);
		return (false);
	}
	else
	{
		if (((*kit)->sdl_window = SDL_CreateWindow("LEM-IN PROJECT",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
		{
			ft_print_error(1, kit);
			return (false);
		}
		else
		{
			if (((*kit)->sdl_renderer = SDL_CreateRenderer((*kit)->sdl_window,
					-1, SDL_RENDERER_ACCELERATED)) == NULL)
			{
				ft_print_error(2, kit);
				return (false);
			}
		}
	}
	return (true);
}

t_vkit		*ft_empty_vkit(void)
{
	t_vkit	*new;

	new = (t_vkit *)malloc(sizeof(t_vkit));
	CHECK(new);
	new->sdl_window = NULL;
	new->sdl_renderer = NULL;
	new->large_font = NULL;
	new->small_font = NULL;
	return (new);
}

t_comp		*ft_empty_comp(void)
{
	t_comp	*new;

	new = (t_comp *)malloc(sizeof(t_comp));
	CHECK(new);
	new->graph = NULL;
	new->edges = NULL;
	new->ants = 0;
	new->set = NULL;
	return (new);
}
