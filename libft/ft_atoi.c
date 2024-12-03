/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:57:19 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 14:18:30 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Converts ASCII string to integer
 *  @param str - string to convert
 *  @return Returns the integer representation of the string
*/
int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	sum;

	sign = 1;
	i = 0;
	sum = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sign * sum);
}

/*int	main()
{
	printf("%i\n", ft_atoi("++123"));
	printf("%i\n", atoi("++123"));
	return (0);
}*/