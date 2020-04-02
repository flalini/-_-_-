/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 09:20:46 by ijang             #+#    #+#             */
/*   Updated: 2020/04/02 19:37:23 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORIZATION_H
# define FACTORIZATION_H
# define ERROR_CASE "errorcase"
# define FILENAME_LEN 9

# include <unistd.h>
# include <fcntl.h>

size_t	ft_find_next_prime(size_t nb);
void	ft_putfactorization(size_t num, int *flag);
void	ft_putnum(size_t num);
char	*ft_hextoi(char *str, size_t *result);
char	*ft_atoi_mark2(char *str, size_t *result);
char	*ft_skipspace(char *str);
char	*ft_checksign(char *str, char *sign);
size_t	ft_initialize(char *str);
void	ft_errorcase_error(void);
void	ft_printerror(int nb);

#endif
