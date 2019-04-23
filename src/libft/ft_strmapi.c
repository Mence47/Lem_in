/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:59:58 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/28 22:27:34 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *p, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	size;

	if (p == NULL)
		return (NULL);
	size = ft_strlen(p);
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = f(i, p[i]);
		i++;
	}
	return (str);
}
