/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:42:25 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/27 14:44:03 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

// int main(void)
// {
// 	t_list *head = NULL;

//     head = ft_lstnew("cd");
//     printf("%s\n", (char *)ft_lstlast(head)->content);

//     head = ft_lstnew("ab");
//     printf("%s\n", (char *)ft_lstlast(head)->content);
//     return (0);
// }
