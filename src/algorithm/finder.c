/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <rtroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:00:00 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/16 17:05:43 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static t_bool	ft_remove_edge(t_node *first, t_node *second)
{
	if (first->tag == START || second->tag == START)
		return (false);
	if (first->tag == END || second->tag == END)
		return (false);
	ft_delete_elem(&(first->adj), second);
	ft_delete_elem(&(second->adj), first);
	return (true);
}

static void		ft_restore_edge(t_node *first, t_node *second)
{
	ft_add_to_list(&(first->adj), second);
	ft_add_to_list(&(second->adj), first);
}

static t_bool	ft_replace(t_paths **new, t_paths **prev)
{
	if ((*new)->turns < (*prev)->turns)
	{
		ft_delete_paths(prev);
		*prev = *new;
		return (true);
	}
	return (false);
}

static void		ft_edge_back(t_paths **new, t_paths *prev, t_list *root)
{
	ft_delete_paths(new);
	ft_restore_edge(root->item, root->item->prev);
	*new = prev;
}

t_paths			*ft_finder(t_graph *graph, unsigned int ant)
{
	t_paths	*prev;
	t_paths	*new;
	t_list	*cross;
	t_list	*root;

	cross = NULL;
	prev = ft_get_paths(graph, ant, &cross);
	root = cross;
	new = prev;
	while (root != NULL)
	{
		if (ft_remove_edge(root->item, root->item->prev) == false)
		{
			root = root->next;
			continue ;
		}
		new = ft_get_paths(graph, ant, NULL);
		if (ft_replace(&new, &prev))
			continue ;
		else
			ft_edge_back(&new, prev, root);
		root = root->next;
	}
	ft_delete_list(&cross);
	return (new);
}
