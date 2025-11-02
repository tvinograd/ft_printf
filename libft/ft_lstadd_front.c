/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:42:15 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/27 12:15:06 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	char *s1 = "cd";
// 	char *s2 = "ab";

// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew(s1);
// 	t_list *node2 = ft_lstnew(s2);

// 	ft_lstadd_front(&head, node1);
// 	printf("[%s]\n", (char *)head->content);

// 	ft_lstadd_front(&head, node2);
// 	printf("[%s]", (char *)head->content);
// 	printf("[%s]\n", (char *)head->next->content);
// 	return (0);
// }
