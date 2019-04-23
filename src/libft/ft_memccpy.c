/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:11 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/28 17:22:49 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)src + i) == (unsigned char)c)
		{
			*((unsigned char*)dst + i) = *((unsigned char*)src + i);
			return (((unsigned char*)dst + i + 1));
		}
		*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		i++;
	}
	return (NULL);
}
