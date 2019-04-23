/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:57:05 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/21 20:45:12 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	int i;
	int j;

	if (*needle == '\0')
		return ((char*)hay);
	i = 0;
	while (hay[i] != '\0')
	{
		j = 0;
		if (hay[i] == needle[j])
		{
			while (needle[j] != '\0')
			{
				if (hay[i + j] != needle[j])
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return ((char*)&hay[i]);
		}
		i++;
	}
	return (NULL);
}
