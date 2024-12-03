/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:50:12 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 16:33:39 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Locates the first occurence of a character in a string
 * 	@param s - string
 *  @param c - character
 *  @return Returns the part of the string that starts with that character
*/
char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	d;

	d = (char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == d)
			return ((char *) &str[i]);
		i++;
	}
	if (d == '\0')
		return ((char *) &str[i]);
	return (NULL);
}
