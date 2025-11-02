/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:42:30 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/28 17:01:40 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		temp = f(lst->content);
		newnode = ft_lstnew(temp);
		if (!newnode)
		{
			del(temp);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}

// void	*ft_return(void *p)
// {
// 	return (p);
// }  

// void	ft_del(void *p)
// {
// 	(void)p;
// }

// int	main(void)
// {
// 	t_list	*node1 = ft_lstnew("abcdefg");
// 	t_list	*node2 = ft_lstnew("klmnopr");
// 	node1->next = node2;

// 	t_list	*newlist = ft_lstmap(node1, ft_return, ft_del);

// 	printf("%s\n", (char *)newlist->content);
// 	printf("%s\n", (char *)newlist->next->content);

// 	ft_lstclear(&newlist, ft_del);
// 	return (0);
// }
