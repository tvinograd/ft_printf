/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:42:17 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/27 15:51:19 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

// void	ft_del(void *p)
// {
// 	(void)p;
// }

// int main(void)
// {
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew("ab");
//     t_list *node2 = ft_lstnew("cd");

// 	head = node1;
// 	node1->next = node2;
// 	printf("[%s]", (char *)head->content);
// 	printf("[%s]\n", (char *)head->next->content);

// 	ft_lstclear(&head, ft_del);
// 	if (head == NULL)
// 		printf("NULL\n");
// 	return (0);
// }
