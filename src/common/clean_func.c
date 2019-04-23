/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:59:56 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/11 20:19:43 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_delete_list(t_list **list)
{
	t_list *tmp;
	t_list *tmp2;

	if (*list == NULL)
		return ;
	tmp = *list;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}

void	ft_delete_paths(t_paths **paths)
{
	unsigned int	i;
	t_list			*tmp;

	i = 0;
	if (paths == NULL || *paths == NULL)
		return ;
	while (i < (*paths)->count)
	{
		tmp = (*paths)->paths[i];
		ft_delete_list(&tmp);
		i++;
	}
	free((*paths)->paths);
	free(*paths);
	*paths = NULL;
}

void	ft_delete_graph(t_graph **graph)
{
	unsigned int	i;
	t_node			*tmp;

	i = 0;
	while (i < (*graph)->count)
	{
		tmp = (*graph)->nodes[i];
		ft_strdel(&(tmp->name));
		ft_delete_list(&(tmp->adj));
		free(tmp);
		i++;
	}
	free((*graph)->nodes);
	free(*graph);
}
