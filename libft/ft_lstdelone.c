/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:42:20 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/27 15:51:35 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void ft_del(void *p)
// {
// 	(void)p;
// }

// int main(void)
// {
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew("ab");
// 	t_list *node2 = ft_lstnew("cd");

// 	head = node1;
// 	node1->next = node2;
// 	printf("[%s]", (char *)head->content);
// 	printf("[%s]\n", (char *)head->next->content);

// 	ft_lstdelone(node1, ft_del);
// 	if (head->next == NULL)
// 		printf("NULL");
// 	printf("[%s]\n", (char *)node2->content);
// 	return (0);
// }
