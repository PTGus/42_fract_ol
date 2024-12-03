/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:01:25 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 16:40:43 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Copies n bytes of memory area of src to the memory area of dest.
 *  Doesn't handle overlapping.
 *  @param dest - destiny memory area
 *  @param src - source memory area
 *  @param n - len of bytes
 *  @return returns the final form of dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	i = 0;
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main()
{
	char	dest[6] = "-----";
	char	*src = "atira";

	printf("Before: %s\n", dest);
	ft_memcpy(dest, src, 5);
	dest[5] = '\0';
	printf("After: %s\n", dest);
	return (0);
}*/