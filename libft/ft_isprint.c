/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:20:49 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 14:20:18 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Checks if it is a printable character
 *  @param c - character value
 *  @return returns 1 if not found and 0 if found
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
