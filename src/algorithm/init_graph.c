/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:58:50 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/02 23:00:53 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	ft_join(char **file, char **line)
{
	char *tmp;

	*file = ft_strjoin_free(file, line);
	tmp = *file;
	*file = ft_strjoin(*file, "\n");
	ft_strdel(&tmp);
}

void	ft_sort_paths(t_paths *paths)
{
	t_list			*tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < paths->count)
	{
		j = 0;
		while (j < paths->count - 1)
		{
			if (ft_list_len(paths->paths[j]) > ft_list_len(paths->paths[j + 1]))
			{
				tmp = paths->paths[j];
				paths->paths[j] = paths->paths[j + 1];
				paths->paths[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
