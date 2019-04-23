/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:43:40 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/16 18:18:07 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	ft_no_way(t_list *tmp, t_list **cross, t_graph *graph,
												t_paths *paths)
{
	if (tmp == NULL)
	{
		if (cross != NULL)
			ft_calc_dist_start(graph, paths, cross);
		return (true);
	}
	return (false);
}

static void		ft_useless_path(t_list *tmp, t_list **cross, t_graph *graph,
										t_paths *paths)
{
	if (cross != NULL)
		ft_calc_dist_start(graph, paths, cross);
	ft_delete_list(&tmp);
}

static t_bool	ft_add(unsigned int turns, unsigned int *prev, t_paths **paths,
		t_list *tmp)
{
	if (turns < *prev)
	{
		*prev = turns;
		ft_expand_paths(paths, tmp);
		return (true);
	}
	return (false);
}

t_paths			*ft_get_paths(t_graph *graph, unsigned int ants, t_list **cross)
{
	t_paths			*paths;
	t_list			*tmp;
	unsigned int	turns;
	unsigned int	prev;

	paths = ft_empty_paths();
	prev = INF;
	while (1)
	{
		ft_calc_dist(graph, paths);
		tmp = ft_find_path(ft_find_start(graph), paths);
		if (ft_no_way(tmp, cross, graph, paths))
			break ;
		turns = ft_turn_count(paths, ants, tmp);
		if (ft_add(turns, &prev, &paths, tmp))
			;
		else
		{
			ft_useless_path(tmp, cross, graph, paths);
			break ;
		}
	}
	paths->turns = prev;
	return (paths);
}
