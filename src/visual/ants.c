/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:27:28 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/26 21:29:22 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static t_ant	*ft_make_ant(int n)
{
	t_ant *new;

	new = (t_ant *)malloc(sizeof(t_ant));
	CHECK(new);
	new->color = NULL;
	new->visited = 0;
	new->number = n + 1;
	return (new);
}

static t_ant	**ft_make_ant_array(int count)
{
	int		i;
	t_ant	**new;

	new = (t_ant **)malloc(sizeof(t_ant) * count);
	CHECK(new);
	i = 0;
	while (i < count)
	{
		new[i] = ft_make_ant(i);
		i++;
	}
	return (new);
}

t_ant			*ft_find_ant(t_ants **ants, int n)
{
	int		i;
	t_ant	*ant;

	i = 0;
	ant = NULL;
	while (i < (int)(*ants)->count)
	{
		if ((*ants)->ant[i]->number == n)
		{
			ant = (*ants)->ant[i];
			return (ant);
		}
		i++;
	}
	return (ant);
}

t_ants			*ft_prepare_ants(int count)
{
	t_ants	*new;

	new = (t_ants *)malloc(sizeof(t_ants));
	CHECK(new);
	new->count = (unsigned int)count;
	new->ant = ft_make_ant_array(count);
	return (new);
}
