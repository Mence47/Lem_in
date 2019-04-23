/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:29:01 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/26 21:31:56 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static t_edge	*ft_make_edge(t_node *a, t_node *b)
{
	t_edge	*new;

	new = (t_edge *)malloc(sizeof(t_edge));
	CHECK(new);
	new->start.x = a->coord.x;
	new->start.y = a->coord.y;
	new->end.x = b->coord.x;
	new->end.y = b->coord.y;
	new->next = NULL;
	return (new);
}

static t_bool	ft_is_edge_exist(t_edge *edge, t_node *a, t_node *b)
{
	t_edge *tmp;

	tmp = edge;
	while (tmp)
	{
		if ((tmp->start.x == a->coord.x && tmp->start.y == a->coord.y) &&
				(tmp->end.x == b->coord.x && tmp->end.y == b->coord.y))
			return (true);
		if ((tmp->end.x == a->coord.x && tmp->end.y == a->coord.y) &&
			(tmp->start.x == b->coord.x && tmp->start.y == b->coord.y))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

static void		ft_tail_edge(t_edge **edges, t_edge *new)
{
	t_edge	*tmp;
	t_edge	*head;

	tmp = *edges;
	head = *edges;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	*edges = head;
}

static void		ft_create_edges(t_edge **edges, t_node *a, t_node *b)
{
	t_edge	*new;

	if (ft_is_edge_exist(*edges, a, b) == false)
	{
		new = ft_make_edge(a, b);
		if (*edges == NULL)
			*edges = new;
		else
			ft_tail_edge(edges, new);
	}
}

void			ft_init_edges(t_comp *comp)
{
	int		i;
	t_list	*head;

	i = 0;
	head = NULL;
	while (i < (int)comp->graph->count)
	{
		head = comp->graph->nodes[i]->adj;
		while (head)
		{
			ft_create_edges(&(comp->edges), comp->graph->nodes[i], head->item);
			head = head->next;
		}
		i++;
	}
}
