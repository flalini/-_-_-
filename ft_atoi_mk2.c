/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mk2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:36:08 by ijang             #+#    #+#             */
/*   Updated: 2020/04/02 21:41:10 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factorization.h"

char	*ft_hextoi(char *str, size_t *result)
{
	size_t	tmp;

	while (*str)
	{
		*result *= 16;
		if (*str > 0x2f && *str < 0x3a)
			tmp = *str - 0x30;
		else if (*str > 0x40 && *str < 0x47)
			tmp = *str - 0x37;
		else if (*str > 0x60 && *str < 0x67)
			tmp = *str - 0x57;
		else
			break ;
		*result += tmp;
		++str;
		if (*result > 0xffffffff)
		{
			*result = 0;
			while ((*str > 0x2f && *str < 0x3a) || (*str > 0x40 && \
						*str < 0x47) || (*str > 0x60 && *str < 0x67))
				++str;
		}
	}
	return (str);
}

char	*ft_atoi_mark2(char *str, size_t *result)
{
	char	base;

	base = 10;
	if (*str == 0x30)
	{
		base = 8;
		++str;
		if (*str == 'x' || *str == 'X')
			return (ft_hextoi(str + 1, result));
		else if(*str == 'b' || *str == 'B')
			base = 2;
		if (base != 8)
			++str;
	}
	while (*str > 0x2f && *str - base < 0x30)
	{
		*result = *result * base + *(str++) - 0x30;
		if (*result > 0xffffffff)
		{
			*result = 0;
			while (*str > 0x2f && *str - base < 0x30)
				++str;
		}
	}
	return (str);
}
