/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <rtroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:23:06 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/16 17:00:00 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		ft_add_to_queue(t_queue *q, t_list **v, t_node *current,
													t_paths *paths)
{
	t_list	*tmp;

	tmp = current->adj;
	while (tmp != NULL)
	{
		if (ft_in_paths(paths, tmp->item) > -1)
		{
			tmp = tmp->next;
			continue ;
		}
		if (ft_in_list(*v, tmp->item) == false)
		{
			ft_enqueue(q, tmp->item);
			ft_add_to_list(v, tmp->item);
			tmp->item->dist = current->dist + 1;
		}
		tmp = tmp->next;
	}
}

void			ft_calc_dist(t_graph *graph, t_paths *paths)
{
	t_node	*end;
	t_node	*tmp;
	t_queue *q;
	t_list	*visited;
	size_t	i;

	i = 0;
	visited = NULL;
	while (i < graph->count)
		graph->nodes[i++]->dist = INF;
	end = ft_find_end(graph);
	end->dist = 0;
	q = ft_create_queue();
	ft_enqueue(q, end);
	ft_add_to_list(&visited, end);
	while (q->head != NULL)
	{
		tmp = ft_dequeue(q);
		ft_add_to_queue(q, &visited, tmp, paths);
	}
	ft_delete_list(&visited);
	ft_delete_queue(&q);
}

static t_node	*ft_min(t_node *node, t_paths *paths)
{
	t_node *min;
	t_list *list;

	list = node->adj;
	if (list == NULL)
		return (NULL);
	while (ft_in_paths(paths, list->item) > -1 && node->tag == START)
	{
		list = list->next;
		if (list == NULL)
			return (NULL);
	}
	min = list->item;
	while (list != NULL)
	{
		if (list->item->dist < min->dist)
			min = list->item;
		list = list->next;
	}
	if (min->dist == INF)
		return (NULL);
	return (min);
}

t_list			*ft_find_path(t_node *start, t_paths *paths)
{
	t_node	*tmp;
	t_node	*prev;

	tmp = start;
	while (tmp->tag != END)
	{
		prev = tmp;
		tmp = ft_min(tmp, paths);
		if (tmp == NULL)
			return (NULL);
		tmp->prev = prev;
	}
	return (ft_return_path(tmp));
}
