/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuphexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:29:45 by gumendes          #+#    #+#             */
/*   Updated: 2024/11/12 11:17:36 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/** @brief Prints a number in it's upercase hexadecimal form
 *  @param nbr The number to be converted and printed
 *  @return Returns the length of the printed number
*/
int	ft_printuphexa(unsigned int nbr)
{
	int		i;
	char	*str;
	int		len;

	len = 0;
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else
	{
		str = helperup(nbr);
		if (!str)
			return (0);
	}
	i = (int)ft_strlen(str);
	while (--i >= 0)
	{
		ft_putchar_fd(str[i], 1);
		len++;
	}
	free(str);
	return (len);
}
