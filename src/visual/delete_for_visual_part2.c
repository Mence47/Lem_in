/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_for_visual_part2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <vrestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:39:45 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/02 22:41:53 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	ft_delete_ant(t_ant **ant)
{
	if (*ant == NULL)
		return ;
	free((*ant)->color);
	(*ant)->color = NULL;
	free(*ant);
	*ant = NULL;
}

void		ft_delete_antarr(t_ants **antarr)
{
	int i;

	if (*antarr == NULL)
		return ;
	i = 0;
	while (i < (int)(*antarr)->count)
	{
		ft_delete_ant(&((*antarr)->ant[i]));
		i++;
	}
	free(*antarr);
	*antarr = NULL;
}

static void	ft_delete_tick(t_tick **tick)
{
	int i;

	if (*tick == NULL)
		return ;
	i = 0;
	while (i < (int)(*tick)->count)
	{
		free((*tick)->antroooms[i]);
		i++;
	}
	free(*tick);
	*tick = NULL;
}

void		ft_delete_set(t_set **set)
{
	int i;

	if (*set == NULL)
		return ;
	i = 0;
	while (i < (int)(*set)->count)
	{
		ft_delete_tick(&((*set)->ticks[i]));
		i++;
	}
	free(*set);
	*set = NULL;
}

void		ft_delete_newcoord(t_newcoord **newcoord)
{
	int i;

	if (*newcoord == NULL)
		return ;
	i = 0;
	while (i < (*newcoord)->count)
	{
		free((*newcoord)->coordarr[i]);
		(*newcoord)->coordarr[i] = NULL;
		i++;
	}
	free(*newcoord);
	*newcoord = NULL;
}
