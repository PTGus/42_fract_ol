/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:55:51 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/30 11:08:47 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Writes a integer on a specified file descriptor
 * 	@param nb - number
 * 	@param fd - specified file descriptor
*/
void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = n;
	if (i < 0)
	{
		i *= -1;
		ft_putchar_fd('-', fd);
	}
	if (i >= 0 && i <= 9)
		ft_putchar_fd(i + '0', fd);
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}
