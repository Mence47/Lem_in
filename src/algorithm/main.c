/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:09:02 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/16 19:18:50 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	ft_add_link(t_graph **graph, char *line)
{
	char	**split;
	size_t	count;

	if (line == NULL)
		return (false);
	count = ft_count_words(line, '-');
	if (count != 2)
		return (false);
	split = ft_strsplit(line, '-');
	if (ft_is_name(split[0], *graph) == false || ft_is_name(split[1],
			*graph) == false)
	{
		ft_clear_split(split);
		return (false);
	}
	ft_make_link(graph, split[0], split[1]);
	ft_clear_split(split);
	return (true);
}

static int		ft_check_for_error(t_graph *graph)
{
	unsigned int i;
	unsigned int j;

	if (ft_find_start(graph) == NULL || ft_find_end(graph) == NULL)
		ft_print_error_a(NULL);
	i = 0;
	while (i < graph->count)
	{
		j = i + 1;
		while (j < graph->count - 1)
		{
			if (ft_strcmp(graph->nodes[i]->name, graph->nodes[j]->name) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int		ft_read_map(t_graph **graph, int *flag, char **line,
							char **file)
{
	while (get_next_line(0, line) != 0)
	{
		if (ft_strlen(*line) == 0)
			break ;
		if (*line[0] == '#')
			ft_command_a(*line, flag);
		else if (ft_add_room_a(graph, flag, *line) == false)
			break ;
		ft_join(file, line);
	}
	if (ft_add_link(graph, *line) == false)
		return (-1);
	ft_join(file, line);
	while (get_next_line(0, line) != 0)
	{
		if (ft_strlen(*line) == 0)
			break ;
		if (*line[0] == '#')
			ft_command_a(*line, flag);
		else if (ft_add_link(graph, *line) == false)
			return (-2);
		ft_join(file, line);
	}
	return (0);
}

char			*ft_init_graph(t_graph **graph, unsigned int *ants)
{
	char	*line;
	char	*file;
	int		flag;

	file = ft_strnew(0);
	flag = REGULAR;
	line = NULL;
	get_next_line(0, &line);
	if (ft_is_number(line) == true && ft_atoi(line) >= 0)
		*ants = (unsigned int)ft_atoi(line);
	else
		ft_print_error_a(&line);
	ft_join(&file, &line);
	ft_read_map(graph, &flag, &line, &file);
	if (line != NULL)
	{
		ft_join(&file, &line);
		while (get_next_line(0, &line) != 0)
			ft_join(&file, &line);
	}
	return (file);
}

int				main(void)
{
	t_graph			*graph;
	unsigned int	ants;
	t_paths			*paths;
	char			*farm;

	graph = ft_empty_graph();
	farm = ft_init_graph(&graph, &ants);
	if (ft_check_for_error(graph) == 1)
		ft_print_error_a(NULL);
	paths = ft_finder(graph, ants);
	if (paths->count == 0)
	{
		ft_delete_paths(&paths);
		ft_delete_graph(&graph);
		ft_strdel(&farm);
		ft_putendl("No solution");
		return (1);
	}
	ft_putendl(farm);
	ft_strdel(&farm);
	ft_sort_paths(paths);
	ft_print_result(paths, ants);
	ft_delete_paths(&paths);
	ft_delete_graph(&graph);
	return (0);
}
