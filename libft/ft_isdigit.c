/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:02:34 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 14:20:07 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief See if it is a digit (0-9)
 *  @param c - character
 *  @return returns 1 if not found and 0 if found
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
