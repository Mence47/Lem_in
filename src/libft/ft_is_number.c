/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:54:30 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/14 20:54:35 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)) == true)
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == false)
			return (false);
		str++;
	}
	return (true);
}
