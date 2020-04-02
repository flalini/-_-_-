/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:57:48 by ijang             #+#    #+#             */
/*   Updated: 2020/04/02 19:46:43 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factorization.h"

void	ft_errorcase_error(void)
{
	write(2, "There are errors in argument and \"", 34);
	write(2, ERROR_CASE, FILENAME_LEN);
	write(2, "\".\n", 3);
}

void	ft_printerror(int nb)
{
	int		fd;
	char	buff;

	fd = open(ERROR_CASE, O_RDONLY);
	if (fd <= 0)
	{
		ft_errorcase_error();
		return ;
	}
	buff = 0;
	while (!(buff = 0) && --nb)
	{
		while (buff != '\n')
			if (!read(fd, &buff, 1))
			{
				ft_errorcase_error();
				close(fd);
				return ;
			}
	}
	while (buff != '\n' && read(fd, &buff, 1))
		write(2, &buff, 1);
	if (buff != '\n')
		write(2, "\n", 1);
	close(fd);
}
