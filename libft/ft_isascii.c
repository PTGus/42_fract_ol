/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:09:50 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 14:19:57 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief See if it is a character of the ASCII Table (0-127 value of ascii)
 *  @param number - character value
 *  @return returns 1 if not found and 0 if found
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
