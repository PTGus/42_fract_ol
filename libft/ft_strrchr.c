/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:41:46 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 16:35:36 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Locates the last occurence of a character in a string
 * 	@param s - string
 *  @param c - character
 *  @return Returns the part of the string that starts with that character
*/
char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		len;
	char	d;

	d = (char) c;
	len = ft_strlen(str);
	i = len - 1;
	while (i >= 0)
	{
		if (str[i] == d)
			return ((char *) &str[i]);
		i--;
	}
	if (d == '\0')
		return ((char *) &str[len]);
	return (NULL);
}
