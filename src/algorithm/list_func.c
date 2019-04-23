/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:16:50 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/06 20:34:05 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

unsigned int	ft_list_len(t_list *list)
{
	unsigned int i;

	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_bool			ft_in_list(t_list *list, t_node *node)
{
	while (list != NULL)
	{
		if (ft_strcmp(list->item->name, node->name) == 0)
			return (true);
		list = list->next;
	}
	return (false);
}

t_node			*ft_find_start(t_graph *graph)
{
	int i;

	i = 0;
	while (i < (int)graph->count)
	{
		if (graph->nodes[i]->tag == START)
			return (graph->nodes[i]);
		i++;
	}
	return (NULL);
}

t_node			*ft_find_end(t_graph *graph)
{
	int i;

	i = 0;
	while (i < (int)graph->count)
	{
		if (graph->nodes[i]->tag == END)
			return (graph->nodes[i]);
		i++;
	}
	return (NULL);
}

void			ft_delete_elem(t_list **list, t_node *node)
{
	t_list *root;
	t_list *tmp;
	t_list *del;

	root = *list;
	if (ft_strcmp(root->item->name, node->name) == 0)
	{
		del = root;
		*list = del->next;
		free(del);
		return ;
	}
	tmp = *list;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (ft_strcmp(tmp->next->item->name, node->name) == 0)
		{
			del = tmp->next;
			tmp->next = del->next;
			free(del);
		}
		tmp = tmp->next;
	}
}
