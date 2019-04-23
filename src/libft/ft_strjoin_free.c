/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:46:24 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/02 21:06:38 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char **s1, char **s2)
{
	char *ptr;

	if (*s1 == NULL || *s2 == NULL)
		return (NULL);
	ptr = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2));
	if (ptr == NULL)
		return (ptr);
	ptr = ft_strcpy(ptr, *s1);
	ptr = ft_strcat(ptr, *s2);
	ft_strdel(s1);
	ft_strdel(s2);
	return (ptr);
}
