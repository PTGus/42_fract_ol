/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:27:51 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 14:11:22 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @brief Adds a new element to the beginning of the list
 *  @param lst - list
 * 	@param new - new element to add
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* int main(void)
{
    t_list *list = NULL;
    t_list *elem1 = malloc(sizeof(t_list));
    t_list *elem2 = malloc(sizeof(t_list));
    t_list *elem3 = malloc(sizeof(t_list));
    elem1->content = "Element 1";
    elem2->content = "Element 2";
    elem3->content = "Element 3";
    ft_lstadd_front(&list, elem1);
    ft_lstadd_front(&list, elem2);
    ft_lstadd_front(&list, elem3);
    printf("Contents of the list:\n");
    t_list *current = list;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
    free(elem1);
    free(elem2);
    free(elem3);
    return 0;
} */