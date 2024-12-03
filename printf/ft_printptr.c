/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:08:10 by gumendes          #+#    #+#             */
/*   Updated: 2024/11/12 11:06:49 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	printer(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr < 16)
	{
		ft_putchar_fd("0123456789abcdef"[ptr], 1);
		len++;
	}
	else
	{
		len += printer(ptr / 16);
		ft_putchar_fd("0123456789abcdef"[ptr % 16], 1);
		len++;
	}
	return (len);
}

/** @brief Prints the address of a pointer in an hexadecimal form
 *  @param add The pointer the which the address will be printed
 *  @return Returns the length of the pointer's address
*/
int	ft_printptr(void *add)
{
	int	len;

	len = 0;
	if (!add)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	write(1, "0x", 2);
	len += 2;
	len += printer((unsigned long)add);
	return (len);
}
