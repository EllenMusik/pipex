/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:30:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/01/27 12:12:42 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c)
{
	return (write(1, &c, 1));
}

int	printstring(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_hexa(size_t nbr, char *numbers, int i)
{
	char	c;

	c = 0;
	if (nbr < 16)
	{
		c = numbers[nbr];
		write(1, &c, 1);
	}
	if (nbr >= 16)
	{
		i = ft_hexa(nbr / 16, numbers, i);
		i = ft_hexa(nbr % 16, numbers, i);
		i++;
	}
	return (i);
}

int	sortingforprint(char strarg, va_list args, int cntr)
{
	if (strarg == 'c')
		cntr += printchar(va_arg(args, int));
	else if (strarg == '%')
		cntr += printchar('%');
	else if (strarg == 's')
		cntr += printstring(va_arg (args, char *));
	else if (strarg == 'i')
		cntr += ft_putnbr_fd1(va_arg(args, int), 1, 1);
	else if (strarg == 'd')
		cntr += ft_putnbr_fd1(va_arg(args, int), 1, 1);
	else if (strarg == 'u')
		cntr += ft_putnbr_unsigned(va_arg(args, unsigned int), 1, 1);
	else if (strarg == 'x')
		cntr += ft_hexa(va_arg(args, unsigned int), "0123456789abcdef", 1);
	else if (strarg == 'X')
		cntr += ft_hexa(va_arg(args, unsigned int), "0123456789ABCDEF", 1);
	else if (strarg == 'p')
	{
		cntr += write(1, "0x", 2);
		cntr += ft_hexa(va_arg(args, size_t), "0123456789abcdef", 1);
	}
	return (cntr);
}

int	ft_printf(const char *strarg, ...)
{
	int		charcount;
	va_list	args;
	int		i;

	charcount = 0;
	i = 0;
	va_start(args, strarg);
	while (strarg[i] != '\0')
	{
		if (strarg[i] == '%')
		{
			i++;
			charcount = sortingforprint(strarg[i], args, charcount);
		}
		else
			charcount += printchar(strarg[i]);
		i++;
	}
	va_end(args);
	return (charcount);
}

// int	main(void)
// {	
// 	//char *str = "hi";
// 	printf("%i\n", printf(" %p ", 16));
// 	printf("%i\n", ft_printf(" %p ", 16));
// 	return (0);
// }
