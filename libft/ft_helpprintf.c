/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfhelp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:17:27 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/27 11:58:01 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd1(int n, int fd, int i)
{
	char	c;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
		i++;
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	if (n > 9)
	{
		i = ft_putnbr_fd1(n / 10, fd, i);
		i = ft_putnbr_fd1(n % 10, fd, i);
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n, unsigned int fd, unsigned int i)
{
	char	c;

	if (n == 0)
		write(fd, "0", 1);
	if (n < 10 && n != 0)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	if (n > 9)
	{
		i = ft_putnbr_unsigned(n / 10, fd, i);
		i = ft_putnbr_unsigned(n % 10, fd, i);
		i++;
	}
	return (i);
}
