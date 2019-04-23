/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ticks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:28:33 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/02 22:47:49 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static t_antroom	*ft_make_ant_room(int num, t_node *room,
		t_ants **ants, SDL_Color *color)
{
	t_antroom	*new;
	t_ant		*ant;
	SDL_Color	*new_color;

	new = (t_antroom *)malloc(sizeof(t_antroom));
	CHECK(new);
	new->room = room;
	ant = ft_find_ant(ants, num);
	if (ant->color == NULL)
	{
		new_color = (SDL_Color *)malloc(sizeof(SDL_Color));
		CHECK(new_color);
		*new_color = *color;
		ant->color = new_color;
	}
	if (ant->visited == 0)
		ant->visited = 1;
	new->ant = ant;
	return (new);
}

static t_antroom	**ft_make_ant_room_array(int count, char **arr,
		t_comp *comp, SDL_Color *color)
{
	t_antroom	*curr;
	t_antroom	**new;
	char		**split;
	char		*tmp;
	int			i;

	new = (t_antroom **)malloc(sizeof(t_antroom *) * count);
	CHECK(new);
	i = 0;
	while (i < count)
	{
		split = ft_strsplit(arr[i], '-');
		tmp = ft_strsub(split[0], 1, ft_strlen(split[0]));
		curr = ft_make_ant_room(ft_atoi(tmp),
				ft_find_room(comp->graph, split[1]),
				&(comp->antarr), color);
		new[i] = curr;
		i++;
	}
	return (new);
}

static int			ft_count_visited(t_ants *ants)
{
	int i;
	int res;

	i = 0;
	res = ants->count;
	while (i < (int)ants->count)
	{
		if (ants->ant[i]->visited == 1)
			res--;
		i++;
	}
	return (res);
}

static t_tick		*ft_make_tick(char *line, t_comp *comp)
{
	t_tick		*new;
	t_antroom	**antrooms;
	int			count;
	char		**split;
	SDL_Color	*color;

	new = (t_tick *)malloc(sizeof(t_tick));
	CHECK(new);
	color = ft_generate_color();
	count = (int)ft_count_words(line, ' ');
	split = ft_strsplit(line, ' ');
	antrooms = ft_make_ant_room_array(count, split, comp, color);
	new->count = (unsigned int)count;
	new->antroooms = antrooms;
	new->left = ft_count_visited(comp->antarr);
	free(color);
	color = NULL;
	return (new);
}

t_tick				**ft_make_ticks(t_comp *comp, char *line)
{
	t_tick		**new;
	int			i;
	int			count;

	count = comp->set->count + 1;
	new = (t_tick **)malloc(sizeof(t_tick *) * count);
	CHECK(new);
	i = 0;
	while (i < (int)comp->set->count)
	{
		new[i] = comp->set->ticks[i];
		i++;
	}
	new[i] = ft_make_tick(line, comp);
	return (new);
}
