/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:42:22 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/27 15:51:53 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void ft_print_str(void *p)
// {
// 	printf("%s\n", (char *)p);
// }

// int main(void)
// {
// 	t_list *node1 = ft_lstnew("abcdefg");
// 	t_list *node2 = ft_lstnew("klmnopr");
// 	node1->next = node2;

// 	ft_lstiter(node1, ft_print_str);
// 		return (0);
// }
