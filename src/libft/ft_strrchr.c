/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:35:34 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/28 23:35:24 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t size;

	size = ft_strlen(s) + 1;
	while (size--)
	{
		if (s[size] == c)
			return ((char *)s + size);
	}
	return (NULL);
}
