/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:06:26 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/28 21:42:04 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnlen(const char *s, size_t n)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && i < n)
		i++;
	return (i);
}

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t size;

	size = ft_strnlen(src, len);
	if (size != len)
		ft_memset(dst + size, '\0', len - size);
	return (ft_memcpy(dst, src, size));
}
