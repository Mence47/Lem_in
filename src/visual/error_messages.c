/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:29:17 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/27 13:24:41 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		ft_error_text(int i)
{
	if (i == 1)
		ft_putendl_fd("Usage: Give me the result of lem-in program", 1);
	else if (i == 2)
		ft_putendl_fd("Graph consider as not printable!", 1);
	exit(1);
}

void		ft_error_visual(t_comp **comp)
{
	ft_delete_comp(comp);
	ft_putendl_fd("Failed to initialize!", 1);
	exit(1);
}
