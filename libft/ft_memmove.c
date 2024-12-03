/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:19:00 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 16:41:26 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Moves n bytes of memory area of src to the memory area of dest.
 *  Handles overlapping.
 *  @param dest - destiny memory area
 *  @param src - source memory area
 *  @param n - len of bytes
 *  @return returns the final form of dest
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((const char *)src)[n];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
