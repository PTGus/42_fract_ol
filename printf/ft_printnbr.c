/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:19:19 by gumendes          #+#    #+#             */
/*   Updated: 2024/11/12 11:06:52 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/** @brief Prints a number
 *  @param nbr The number to be printed
 *  @return Returns the length of the printed number
*/
int	ft_printnbr(int nbr)
{
	long int	i;
	int			len;

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
