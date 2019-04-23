/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:43:46 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/21 16:59:40 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1);
	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (ptr != NULL)
	{
		i = 0;
		while (i < size)
		{
			ptr[i] = *s1;
			i++;
			s1++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
