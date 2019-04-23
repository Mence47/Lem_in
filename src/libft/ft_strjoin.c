/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:46:24 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/28 19:46:44 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (ptr == NULL)
		return (ptr);
	ptr = ft_strcpy(ptr, s1);
	ptr = ft_strcat(ptr, s2);
	return (ptr);
}
