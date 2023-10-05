/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:18:09 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/27 11:23:17 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int	ft_putnbr_fd1(int n, int fd, int i);
int	ft_putnbr_unsigned(unsigned int n, unsigned int fd, unsigned int i);
int	printchar(char c);
int	printstring(char *str);
int	fthexa(size_t nbr, char *numbers, int i);
int	sortingforprint(char strarg, va_list args, int cntr);
int	ft_printf(const char *strarg, ...);

#endif