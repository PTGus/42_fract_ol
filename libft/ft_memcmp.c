/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:53:21 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 14:25:24 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Compares byte strings
 * 	@param s1 - string one
 *  @param s2 - string two
 * 	@param n - number of bytes to search
 *  @return Returns difference of the different bytes if located.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char	*s1 = NULL;
	const char	*s2 = "123";
	size_t n = 4;
	const void	*str1 = (const void *) s1;
	const void	*str2 = (const void *) s2;
	printf("%i", ft_memcmp(str1, str2, n));
	return (0);
}*/