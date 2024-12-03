/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlowhexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:52:09 by gumendes          #+#    #+#             */
/*   Updated: 2024/11/12 11:17:36 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/** @brief Prints a number in it's lowercase hexadecimal form
 *  @param nbr The number to be converted and printed
 *  @return Returns the length of the printed number
*/
int	ft_printlowhexa(unsigned int nbr)
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
		str = helperlow(nbr);
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
