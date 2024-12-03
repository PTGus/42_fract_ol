/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:27:02 by gumendes          #+#    #+#             */
/*   Updated: 2024/11/12 11:17:36 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_intlen(unsigned int nbr)
{
	int		count;

	count = 0;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*helperlow(unsigned int nbr)
{
	int		i;
	int		remainder;
	char	*hex;
	char	*str;

	hex = "0123456789abcdef";
	i = 0;
	str = ft_calloc(ft_intlen(nbr) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[i++] = '0';
	while (nbr > 0)
	{
		remainder = nbr % 16;
		str[i++] = hex[remainder];
		nbr /= 16;
	}
	return (str);
}

char	*helperup(unsigned int nbr)
{
	int		i;
	int		remainder;
	char	*hex;
	char	*str;

	hex = "0123456789ABCDEF";
	i = 0;
	str = ft_calloc(ft_intlen(nbr) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[i++] = '0';
	while (nbr > 0)
	{
		remainder = nbr % 16;
		str[i++] = hex[remainder];
		nbr /= 16;
	}
	return (str);
}
