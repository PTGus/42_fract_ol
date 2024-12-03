/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:19:30 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 14:23:36 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Locates byte in byte string
 * 	@param s1 - string
 *  @param c - character
 * 	@param n - number of bytes to search
 *  @return Returns the pointer of the byte located
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			d;
	const unsigned char		*str;

	d = (unsigned char) c;
	str = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == d)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
