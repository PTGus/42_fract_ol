/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:24:44 by gumendes          #+#    #+#             */
/*   Updated: 2024/11/12 11:06:56 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_formatter(va_list args, const char type)
{
	if (type == 'a')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (type == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_printptr(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_printunbr(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_printlowhexa(va_arg(args, unsigned int)));
	else if (type == 'X')
		return (ft_printuphexa(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += ft_formatter(args, str[i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/* int main(void)
{
	int count;

	// String test
	count = ft_printf("Hello, %s!\n", "world");
	printf("Printed characters: %d\n\n", count);

	// Integer test
	count = ft_printf("Integer: %d\n", 42);
	printf("Printed characters: %d\n\n", count);

	// Usigned integer test
	count = ft_printf("Unsigned integer: %u\n", -4294967296);
	printf("Printed characters: %d\n\n", count);

	// Pointer address test
	int a = 10;
	count = ft_printf("Pointer address: %p\n", (void *)&a);
	printf("Printed characters: %d\n\n", count);

	// Lowercase hexadecimal test
	count = ft_printf("Hex (lowercase): %x\n", 9999);
	printf("Printed characters: %d\n\n", count);

	// Uppercase hexadecimal test
	count = ft_printf("Hex (uppercase): %X\n", 9999);
	printf("Printed characters: %d\n\n", count);

	// Percent sign test
	count = ft_printf("Percent sign: %%\n");
	printf("Printed characters: %d\n\n", count);

	return 0;
} */