/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_graph_visual.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:28:12 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/28 19:03:53 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	ft_command(char *line, int *flag)
{
	if (ft_strcmp(line, "##start") == 0)
		*flag = START;
	else if (ft_strcmp(line, "##end") == 0)
		*flag = END;
	else
		*flag = REGULAR;
}

static void	ft_add_room(t_graph **graph, int *flag, char *line)
{
	char	**split;
	t_node	*room;

	split = ft_strsplit(line, ' ');
	if ((room = ft_make_room(split[0], ft_atoi(split[1]),
			ft_atoi(split[2]), flag)))
		ft_expand_graph(graph, room);
	ft_clear_split(split);
}

static void	ft_add_link(t_graph **graph, char *line)
{
	char	**split;

	split = ft_strsplit(line, '-');
	ft_make_link(graph, split[0], split[1]);
	ft_clear_split(split);
}

void		ft_read_graph(t_comp *comp, char **line, int *fd)
{
	int		flag;

	flag = REGULAR;
	get_next_line(*fd, line);
	if (*line == NULL || (ft_strcmp(*line, "Error\n") == 0)
		|| (ft_strcmp(*line, "No solution\n") == 0))
		exit(1);
	comp->ants = (unsigned int)ft_atoi(*line);
	ft_strdel(line);
	while (get_next_line(*fd, line) != 0)
	{
		if (ft_strlen(*line) == 0)
			break ;
		if (*line[0] == '#')
			ft_command(*line, &flag);
		else if (ft_strchr(*line, ' ') != NULL)
			ft_add_room(&(comp->graph), &flag, *line);
		else if (ft_strchr(*line, '-') != NULL)
			ft_add_link(&(comp->graph), *line);
		else
			break ;
		ft_strdel(line);
	}
	ft_strdel(line);
}
