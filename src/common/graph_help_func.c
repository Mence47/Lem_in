/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_help_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:35:20 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/02 19:15:37 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	ft_is_name(char *name, t_graph *graph)
{
	unsigned int i;

	i = 0;
	while (i < graph->count)
	{
		if (ft_strcmp(graph->nodes[i]->name, name) == 0)
			return (true);
		i++;
	}
	return (false);
}

t_node	*ft_find_room(t_graph *graph, char *name)
{
	unsigned int i;

	i = 0;
	while (i < graph->count)
	{
		if (ft_strcmp(graph->nodes[i]->name, name) == 0)
			return (graph->nodes[i]);
		i++;
	}
	return (NULL);
}

void	ft_add_to_list(t_list **list, t_node *link)
{
	t_list	*tmp;

	tmp = *list;
	*list = (t_list *)malloc(sizeof(t_list));
	CHECK_VOID(*list);
	(*list)->next = tmp;
	(*list)->item = link;
}

void	ft_make_link(t_graph **graph, char *a, char *b)
{
	ft_add_to_list(&(ft_find_room(*graph, a)->adj), ft_find_room(*graph, b));
	ft_add_to_list(&(ft_find_room(*graph, b)->adj), ft_find_room(*graph, a));
}

t_graph	*ft_empty_graph(void)
{
	t_graph *graph;

	graph = (t_graph *)malloc(sizeof(t_graph));
	CHECK(graph);
	graph->count = 0;
	graph->nodes = NULL;
	return (graph);
}
