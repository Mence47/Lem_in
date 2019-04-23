/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:29:05 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/28 22:32:22 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	char	*buf;
	char	*buf1;
	size_t	x;

	buf = (char*)destptr;
	buf1 = (char*)srcptr;
	x = -1;
	if (buf1 < buf)
	{
		while ((int)(--num) >= 0)
			*(buf + num) = *(buf1 + num);
	}
	else
	{
		while (++x < num)
			*(buf + x) = *(buf1 + x);
	}
	return (destptr);
}
