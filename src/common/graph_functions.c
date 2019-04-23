/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:38:31 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/11 20:19:43 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node			*ft_make_room(char *str, int a, int b, int *flag)
{
	t_node	*room;
	t_point	dot;

	dot.x = a;
	dot.y = b;
	room = (t_node *)malloc(sizeof(t_node));
	CHECK(room);
	room->name = ft_strdup(str);
	room->tag = *flag;
	room->ant = 0;
	room->dist = 0;
	if (*flag == START || *flag == END)
		*flag = REGULAR;
	room->prev = NULL;
	room->coord = dot;
	room->adj = NULL;
	room->alt = NULL;
	return (room);
}

t_list			*ft_list_dup(t_list *list)
{
	t_list *new;
	t_list *result;
	t_list *root;

	new = NULL;
	while (list != NULL)
	{
		ft_add_to_list(&new, list->item);
		list = list->next;
	}
	root = new;
	result = NULL;
	while (new != NULL)
	{
		ft_add_to_list(&result, new->item);
		new = new->next;
	}
	ft_delete_list(&root);
	return (result);
}

static t_node	*ft_node_dup(t_node *node)
{
	t_node *new;

	new = (t_node*)malloc(sizeof(t_node));
	new->name = ft_strdup(node->name);
	new->tag = node->tag;
	new->prev = NULL;
	new->adj = ft_list_dup(node->adj);
	new->coord = node->coord;
	new->ant = node->ant;
	return (new);
}

static t_node	**ft_make_room_array(t_graph *graph, t_node *room)
{
	t_node			**nodes;
	unsigned int	count;
	unsigned int	i;

	count = graph->count + 1;
	nodes = (t_node **)malloc(sizeof(t_node *) * count);
	CHECK(nodes);
	i = 0;
	while (i < graph->count)
	{
		nodes[i] = ft_node_dup(graph->nodes[i]);
		i++;
	}
	nodes[i] = room;
	return (nodes);
}

void			ft_expand_graph(t_graph **graph, t_node *room)
{
	t_graph			*new;
	t_node			**nodes;

	nodes = ft_make_room_array(*graph, room);
	new = (t_graph *)malloc(sizeof(t_graph));
	CHECK_VOID(new);
	new->count = (*graph)->count + 1;
	new->nodes = nodes;
	ft_delete_graph(graph);
	*graph = new;
}
