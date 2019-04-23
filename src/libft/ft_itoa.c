/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:52:03 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/28 21:25:03 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

static	char	*ft_alloc_zero(void)
{
	char	*ptr;

	ptr = ft_strnew(1);
	ptr[0] = '0';
	return (ptr);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	size_t	i;
	int		sign;
	long	result;

	if (n == 0)
		return (ft_alloc_zero());
	result = n;
	sign = n;
	if (result < 0)
		result = result * -1;
	ptr = ft_strnew(10 + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (result != 0)
	{
		ptr[i++] = result % 10 + '0';
		result /= 10;
	}
	if (sign < 0)
		ptr[i++] = '-';
	return (ft_strrev(ptr));
}
