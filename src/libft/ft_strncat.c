/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:27:08 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/28 23:00:35 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < n)
		i++;
	return (i);
}

char			*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	size_t	size_src;

	i = 0;
	while (dest[i] != '\0')
		i++;
	size_src = ft_strnlen(src, n);
	dest[i + size_src] = '\0';
	ft_memcpy(&dest[i], src, size_src);
	return (dest);
}
