/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:28:20 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/27 13:03:38 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_set			*ft_empty_set(void)
{
	t_set *new;

	new = (t_set *)malloc(sizeof(t_set));
	CHECK(new);
	new->count = 0;
	new->ticks = NULL;
	return (new);
}

static void		ft_expand_set(t_comp *comp, char *line)
{
	t_set	*new;
	t_tick	**ticks;

	new = (t_set *)malloc(sizeof(t_set));
	CHECK_VOID(new);
	new->count = (comp->set)->count + 1;
	ticks = ft_make_ticks(comp, line);
	new->ticks = ticks;
	free(comp->set);
	comp->set = new;
}

void			ft_read_set(t_comp *comp, char **line, int *fd)
{
	while (get_next_line(*fd, line) != 0)
	{
		if (*line[0] == 'L')
			ft_expand_set(comp, *line);
		else
			break ;
		ft_strdel(line);
	}
	ft_strdel(line);
}
