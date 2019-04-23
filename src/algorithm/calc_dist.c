/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <rtroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:17:38 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/16 18:19:34 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static t_list	*ft_add_to_queue(t_queue *q, t_list **v, t_node *current,
						t_paths *paths)
{
	t_list	*tmp;
	t_list	*cross;

	cross = NULL;
	tmp = current->adj;
	while (tmp != NULL)
	{
		if (ft_in_paths(paths, tmp->item) > -1)
		{
			if (tmp->item->tag != START && tmp->item->prev->tag != START &&
				tmp->item->tag != END && ft_is_way(current, paths, *v) == false)
				ft_add_to_list(&cross, tmp->item);
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
	return (cross);
}

static void		ft_add_to_cross(t_list **cross, t_list *to_cross)
{
	t_list *tmp;

	if (*cross == NULL)
	{
		*cross = to_cross;
		return ;
	}
	tmp = *cross;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = to_cross;
}

void			ft_calc_dist_start(t_graph *graph, t_paths *paths,
									t_list **cross)
{
	t_node	*start;
	t_node	*tmp;
	t_queue *q;
	t_list	*visited;
	size_t	i;

	i = 0;
	visited = NULL;
	while (i < graph->count)
		graph->nodes[i++]->dist = INF;
	start = ft_find_start(graph);
	start->dist = 0;
	q = ft_create_queue();
	ft_enqueue(q, start);
	ft_add_to_list(&visited, start);
	while (q->head != NULL)
	{
		tmp = ft_dequeue(q);
		ft_add_to_cross(cross, ft_add_to_queue(q, &visited, tmp, paths));
	}
	ft_delete_queue(&q);
	ft_delete_list(&visited);
}
