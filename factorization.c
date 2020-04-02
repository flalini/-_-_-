/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 09:20:46 by ijang             #+#    #+#             */
/*   Updated: 2020/04/02 19:54:51 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factorization.h"

size_t	ft_find_next_prime(size_t nb)
{
	size_t	cal;

	while (nb < 0x100000000)
	{
		cal = 2;
		while (cal * cal <= nb)
		{
			if (nb % cal == 0)
				break ;
			++cal;
		}
		if (cal * cal > nb)
			return (nb);
		++nb;
	}
	return (0);
}

void	ft_putfactorization(size_t num, int *flag)
{
	if (*flag)
		*flag = 0;
	else
		write(1, " ", 1);
	ft_putnum(num);
}

void	ft_putnum(size_t num)
{
	char	c;

	if (num >= 10)
		ft_putnum(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	size_t	argi;
	size_t	cal;

	if (argc != 2)
	{
		ft_printerror(1);
		return (1);
	}
	if ((argi = ft_initialize(argv[1])))
	{
		cal = 2;
		while (cal * cal <= argi)
		{
			if (argi % cal == 0)
				ft_putfactorization(cal, &argc);
			while (argi % cal == 0)
				argi /= cal;
			cal = ft_find_next_prime(cal + 1);
		}
		if (argi != 1)
			ft_putfactorization(argi, &argc);
		write(1, "\n", 1);
		return (0);
	}
	return (1);
}
