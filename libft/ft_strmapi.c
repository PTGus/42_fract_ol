/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:44:41 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 16:35:01 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Apllies a function to each character of a string
 * 	@param s - string
 * 	@param f - function
 *  @return Returns the string
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*temp;

	if (!s)
		return (NULL);
	temp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		temp[i] = (*f)(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
