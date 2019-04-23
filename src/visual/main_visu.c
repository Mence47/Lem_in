/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:28:51 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/02 22:44:12 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		ft_visual_close(t_vkit **kit)
{
	ft_delete_visual_kit(kit);
	TTF_Quit();
	SDL_Quit();
}

static void		ft_draw_part(t_vkit **kit, int flag, t_comp *comp)
{
	SDL_Color *color;

	color = ft_make_color(255, 255, 255);
	SDL_SetRenderDrawColor((*kit)->sdl_renderer, 0xD3, 0xD3, 0xD3, 0xD3);
	SDL_RenderClear((*kit)->sdl_renderer);
	ft_draw_edges((*kit)->sdl_renderer, comp->edges);
	ft_draw_circles((*kit)->sdl_renderer, comp->graph, color);
	ft_render_room_names(*kit, comp->graph);
	ft_render_corner_text(*kit);
	if (flag == 0)
		ft_render_text_ants(*kit, comp->ants);
	if (flag)
	{
		ft_render_text_ants(*kit, comp->set->ticks[flag - 1]->left);
		ft_show_ticks((*kit)->sdl_renderer, &(comp->set), flag - 1);
	}
	SDL_RenderPresent((*kit)->sdl_renderer);
	free(color);
}

static void		ft_keyboard_loop(SDL_Event *e, int *flag, t_comp *comp)
{
	if ((*e).key.keysym.sym == SDLK_SPACE)
	{
		(*flag)++;
		if (*flag > (int)comp->set->count)
			*flag = 0;
	}
}

static void		ft_visual_loop(t_comp *comp)
{
	t_vkit		*kit;
	t_bool		quit;
	int			flag;
	SDL_Event	e;

	kit = ft_empty_vkit();
	if (!ft_sdl_init(&kit) || !ft_ttf_init(&kit))
		ft_error_visual(&comp);
	else
	{
		quit = false;
		flag = 0;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
					quit = true;
				else if (e.type == SDL_KEYUP)
					ft_keyboard_loop(&e, &flag, comp);
			}
			ft_draw_part(&kit, flag, comp);
		}
	}
	ft_visual_close(&kit);
}

int				main(int argc, const char *argv[])
{
	t_comp	*comp;
	char	*line;
	int		fd;

	if (argc > 1)
	{
		ft_putendl_fd(argv[0], 1);
		ft_error_text(1);
	}
	fd = 0;
	comp = ft_empty_comp();
	comp->graph = ft_empty_graph();
	ft_read_graph(comp, &line, &fd);
	if (comp->graph->count > 1002)
		ft_error_text(2);
	ft_change_coord(&(comp->graph));
	comp->antarr = ft_prepare_ants(comp->ants);
	ft_init_edges(comp);
	comp->set = ft_empty_set();
	ft_read_set(comp, &line, &fd);
	ft_visual_loop(comp);
	ft_delete_comp(&comp);
	exit(0);
}
