/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:45:44 by ijang             #+#    #+#             */
/*   Updated: 2020/04/02 19:00:17 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factorization.h"

char	*ft_skipspace(char *str)
{
	if (*str == 0x20 || (*str > 0x08 && *str < 0x0f))
		++str;
	return (str);
}

char	*ft_checksign(char *str, char *sign)
{
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign *= -1;
		++str;
	}
	while ((*(str - 1) != *str) && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			*sign *= -1;
		++str;
	}
	return (str);
}

size_t	ft_initialize(char *str)
{
	size_t	result;
	char	sign;

	sign = 1;
	str = ft_skipspace(str);
	str = ft_checksign(str, &sign);
	if (*str < '0' || *str > '9')
	{
		ft_printerror(2);
		return (0);
	}
	if (sign == -1)
	{
		ft_printerror(3);
		return (0);
	}
	result = 0;
	str = ft_atoi_mark2(str, &result);
	str = ft_skipspace(str);
	if (*str || !result || result == 1)
	{
		ft_printerror((*str ? 2 : 3));
		return (0);
	}
	return (result);
}
