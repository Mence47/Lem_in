/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:20:27 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/16 17:05:43 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_list			*ft_return_path(t_node *end)
{
	t_list *path;

	path = NULL;
	ft_add_to_list(&path, end);
	while (path->item->prev != NULL)
	{
		end = end->prev;
		ft_add_to_list(&path, end);
	}
	return (path);
}

int				ft_in_paths(t_paths *paths, t_node *node)
{
	unsigned int	i;
	t_list			*tmp;

	i = 0;
	while (i < paths->count)
	{
		tmp = paths->paths[i];
		while (tmp != NULL)
		{
			if (ft_strcmp(node->name, tmp->item->name) == 0)
				return (i);
			tmp = tmp->next;
		}
		i++;
	}
	return (-1);
}

t_paths			*ft_empty_paths(void)
{
	t_paths *graph;

	graph = (t_paths *)malloc(sizeof(t_paths));
	CHECK(graph);
	graph->count = 0;
	graph->paths = NULL;
	return (graph);
}

unsigned int	ft_turn_count(t_paths *path, unsigned int ants, t_list *new)
{
	unsigned int	count;
	unsigned int	big_path;
	unsigned int	turns;
	int				i;

	count = 0;
	big_path = 1;
	turns = 0;
	while (count < ants)
	{
		count = 0;
		i = path->count;
		turns = ft_list_len(new) - 1 + big_path;
		while (--i >= 0)
			count += turns - (ft_list_len(path->paths[i]) - 1);
		count += big_path;
		big_path++;
	}
	return (turns);
}

t_bool			ft_is_way(t_node *node, t_paths *paths, t_list *v)
{
	t_list *adj;

	adj = node->adj;
	while (adj != NULL)
	{
		if (ft_in_paths(paths, adj->item) == -1 &&
							ft_in_list(v, adj->item) == false)
			return (true);
		adj = adj->next;
	}
	return (false);
}
