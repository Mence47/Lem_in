/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:09:51 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/16 20:13:58 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		ft_print_current(t_node *room, unsigned int *end)
{
	if (room->ant == 0)
		return ;
	ft_putchar('L');
	ft_putnbr(room->ant);
	ft_putchar('-');
	ft_putstr(room->name);
	ft_putchar(' ');
	if (room->tag == END)
		*end = *end + 1;
}

static void		ft_go_to_next(t_list *list, unsigned int *end)
{
	int tmp;
	int tmp2;

	tmp = 0;
	while (list->item->tag != END)
	{
		tmp2 = list->item->ant;
		list->item->ant = tmp;
		if (tmp != 0)
			ft_print_current(list->item, end);
		tmp = tmp2;
		list = list->next;
	}
	list->item->ant = tmp;
	ft_print_current(list->item, end);
}

static void		ft_move(t_paths *paths, unsigned int *end)
{
	unsigned int j;

	j = 0;
	while (j < paths->count)
	{
		ft_go_to_next(paths->paths[j]->next, end);
		j++;
	}
}

static t_bool	ft_is_enough(t_paths *paths, unsigned int ants, int j)
{
	unsigned int count;

	count = 0;
	while (--j >= 0)
		count += paths->turns - ft_list_len(paths->paths[j]);
	if (count >= ants)
		return (true);
	return (false);
}

void			ft_print_result(t_paths *paths, unsigned int ants)
{
	static unsigned int	i = 1;
	static unsigned int	count_end = 0;
	int					j;
	unsigned int		tmp;

	tmp = ants;
	while (count_end < tmp)
	{
		j = -1;
		while (++j < (int)paths->count && ants > 0)
		{
			if (paths->paths[j]->next->item->ant == 0)
			{
				paths->paths[j]->next->item->ant = i++;
				ft_print_current(paths->paths[j]->next->item, &count_end);
				ants--;
			}
			if (j + 1 < (int)paths->count && ft_is_enough(paths, ants, j + 1))
				break ;
		}
		paths->turns--;
		ft_putchar('\n');
		ft_move(paths, &count_end);
	}
	ft_putchar('\n');
}
