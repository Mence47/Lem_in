/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:03:27 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/22 22:10:11 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(size);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < size)
	{
		*((char*)ptr + i) = 0;
		i++;
	}
	return (ptr);
}
