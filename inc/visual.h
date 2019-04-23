/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:20:03 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/16 20:08:22 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_VISUAL_H
# define LEM_IN_VISUAL_H

# include <SDL.h>
# include <SDL_ttf.h>
# include "lem_in.h"
# include <stdlib.h>
# define SCREEN_WIDTH 1500
# define SCREEN_HEIGHT 1000
# define AREA_X (SCREEN_WIDTH - 200)
# define AREA_Y (SCREEN_HEIGHT - 200)
# define SCR_CEN_X (SCREEN_WIDTH / 2)
# define SCR_CEN_Y (SCREEN_HEIGHT / 2)
# define RADIUS 8
# define STEP (2 * RADIUS + 1)
# define FONT "Type.ttf"

typedef struct			s_rect
{
	t_point				bottom;
	t_point				top;
	int					height;
	int					width;
}						t_rect;

typedef struct			s_edge
{
	t_point				start;
	t_point				end;
	struct s_edge		*next;
}						t_edge;

typedef struct			s_ant
{
	SDL_Color			*color;
	int					visited;
	int					number;
}						t_ant;

typedef struct			s_ants
{
	unsigned int		count;
	struct s_ant		**ant;
}						t_ants;

typedef struct			s_antroom
{
	t_node				*room;
	struct s_ant		*ant;
}						t_antroom;

typedef struct			s_tick
{
	unsigned int		count;
	int					left;
	struct s_antroom	**antroooms;
}						t_tick;

typedef struct			s_set
{
	unsigned int		count;
	struct s_tick		**ticks;
}						t_set;

typedef struct			s_vkit
{
	SDL_Window			*sdl_window;
	SDL_Renderer		*sdl_renderer;
	TTF_Font			*small_font;
	TTF_Font			*large_font;
}						t_vkit;

typedef struct			s_comp
{
	t_graph				*graph;
	t_edge				*edges;
	unsigned int		ants;
	t_ants				*antarr;
	t_set				*set;
}						t_comp;

typedef struct			s_text
{
	SDL_Surface			*sdl_surface;
	SDL_Texture			*message;
	SDL_Rect			sdl_rect;
	int					width;
	int					height;
}						t_text;

typedef	struct			s_ncoord
{
	int					tag;
	t_point				coord;
}						t_ncoord;

typedef struct			s_newcoord
{
	int					count;
	struct s_ncoord		**coordarr;
}						t_newcoord;

void					ft_read_graph(t_comp *comp, char **line, int *fd);
void					ft_read_set(t_comp *comp, char **line, int *fd);
void					ft_init_edges(t_comp *comp);
t_ant					*ft_find_ant(t_ants **ants, int n);
t_rect					*ft_find_rectangle(t_graph **graph, int i);
void					ft_change_coord(t_graph **graph);
t_bool					is_bigger_than_map(t_graph *graph);
void					ft_remake_coord(t_graph **graph, t_rect **rect);
t_ants					*ft_prepare_ants(int count);
t_tick					**ft_make_ticks(t_comp *comp, char *line);
void					ft_delete_text_color(t_text **text, SDL_Color **color);
void					ft_delete_text(t_text **text);
void					ft_delete_visual_kit(t_vkit **kit);
void					ft_delete_antarr(t_ants **antarr);
void					ft_delete_set(t_set **set);
void					ft_delete_comp(t_comp **comp);
void					ft_delete_newcoord(t_newcoord **newcoord);
void					ft_error_text(int i);
void					ft_error_visual(t_comp **comp);

t_set					*ft_empty_set(void);
t_text					*ft_empty_text(void);
t_vkit					*ft_empty_vkit(void);
t_comp					*ft_empty_comp(void);
int						ft_abs(int num);

t_bool					ft_sdl_init(t_vkit **kit);
t_bool					ft_ttf_init(t_vkit **kit);
SDL_Color				*ft_generate_color(void);
SDL_Color				*ft_make_color(Uint8 r, Uint8 g, Uint8 b);
void					ft_draw_circle(SDL_Renderer *r, t_node *room,
										SDL_Color *color);
void					ft_draw_circles(SDL_Renderer *r, t_graph *graph,
										SDL_Color *color);
void					ft_draw_edges(SDL_Renderer *r, t_edge *edges);
void					ft_render_corner_text(t_vkit *kit);
void					ft_render_text_ants(t_vkit *kit, int number);
void					ft_render_room_names(t_vkit *kit, t_graph *graph);
void					ft_show_ticks(SDL_Renderer *r, t_set **set, int flag);
t_newcoord				*ft_init_coordarr(int nodes);

#endif
