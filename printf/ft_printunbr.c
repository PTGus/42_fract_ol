/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:34:49 by gumendes          #+#    #+#             */
/*   Updated: 2024/11/12 11:06:42 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/** @brief Prints an unsigned integer
 *  @param nbr The integer to be printed
 *  @return Returns the length of the printed integer
*/
int	ft_printunbr(unsigned int nbr)
{
	unsigned int	i;
	int				len;

	i = nbr;
	len = 0;
	if (i < 0)
	{
		i *= -1;
		ft_putchar_fd('-', 1);
		len++;
	}
	if (i >= 0 && i <= 9)
	{
		ft_putchar_fd(i + '0', 1);
		len++;
	}
	if (i > 9)
	{
		len += ft_printnbr(i / 10);
		len += ft_printnbr(i % 10);
	}
	return (len);
}
