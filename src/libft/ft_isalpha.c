/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:42:17 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/28 20:33:29 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c > 127 || c < 0)
		return (0);
	if (((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
			|| ((unsigned char)c >= 'a' && (unsigned char)c <= 'z'))
		return (1);
	return (0);
}
