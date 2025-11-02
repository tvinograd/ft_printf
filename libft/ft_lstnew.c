/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:42:45 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/27 17:39:34 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int main(void)
// {
// 	char *s1 = "Hello";
// 	char *s2 = "Apple";

// 	t_list	*node1 = ft_lstnew(s1);
// 	t_list	*node2 = ft_lstnew(s2);

// 	printf("%s\n", (char *)node1->content);
// 	printf("%p\n", (char *)node1->next);

// 	node1->next = node2;
// 	printf("%p\n", (char *)node1->next);
// 	printf("%s\n", (char *)node1->next->content);
//	return (0);
// }
