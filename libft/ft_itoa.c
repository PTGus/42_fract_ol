/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:16:16 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 14:23:58 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long nbr)
{
	int		count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*convert(char *str, long n, int len)
{
	int	i;

	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	i = len - 1;
	while (n)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}

/** @brief Puts each digit into the string
 * 	@param n - number
 * 	@param str - string
 * 	@param i - index of string
 *  @return Returns the string
*/
char	*ft_itoa(int n)
{
	long	m;
	int		i;
	char	*str;

	m = n;
	i = ft_intlen(m);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	return (convert(str, m, i));
}
