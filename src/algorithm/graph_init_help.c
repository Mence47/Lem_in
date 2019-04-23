/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:02:55 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/16 19:54:04 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	ft_print_error_a(char **str)
{
	ft_strdel(str);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_command_a(char *line, int *flag)
{
	static int start = 0;
	static int finish = 0;

	if (ft_strcmp(line, "##start") == 0)
	{
		if (start == 1)
			ft_print_error_a(&line);
		*flag = START;
		start = 1;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (finish == 1)
			ft_print_error_a(&line);
		*flag = END;
		finish = 1;
	}
	else
		*flag = REGULAR;
}

t_list	**ft_add_path(t_paths *paths, t_list *new_path)
{
	t_list			**list;
	unsigned int	count;
	unsigned int	i;

	count = paths->count + 1;
	list = (t_list **)malloc(sizeof(t_list *) * count);
	CHECK(list);
	i = 0;
	while (i < paths->count)
	{
		list[i] = ft_list_dup(paths->paths[i]);
		i++;
	}
	list[i] = ft_list_dup(new_path);
	return (list);
}

void	ft_expand_paths(t_paths **paths, t_list *new_path)
{
	t_paths *new;
	t_list	**tmp;

	tmp = ft_add_path(*paths, new_path);
	new = (t_paths *)malloc(sizeof(t_paths));
	CHECK_VOID(new);
	new->count = (*paths)->count + 1;
	new->paths = tmp;
	ft_delete_paths(paths);
	ft_delete_list(&new_path);
	*paths = new;
}

t_bool	ft_add_room_a(t_graph **graph, int *flag, char *line)
{
	char	**split;
	size_t	count;
	t_node	*room;

	count = ft_count_words(line, ' ');
	if (count != 3)
		return (false);
	split = ft_strsplit(line, ' ');
	if (split[0][0] == 'L')
	{
		ft_clear_split(split);
		return (false);
	}
	if (ft_is_number(split[1]) == false || ft_is_number(split[2]) == false)
	{
		ft_clear_split(split);
		return (false);
	}
	if ((room = ft_make_room(split[0], ft_atoi(split[1]), ft_atoi(split[2]),
	flag)))
		ft_expand_graph(graph, room);
	ft_clear_split(split);
	return (true);
}
