/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:42:11 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/27 12:54:04 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

// int main(void)
// {
// 	t_list *head = NULL;

// 	ft_lstadd_back(&head, ft_lstnew("ab"));
// 	printf("[%s]\n", (char *)head->content);

// 	ft_lstadd_back(&head, ft_lstnew("cd"));
// 	printf("[%s]", (char *)head->content);
// 	printf("[%s]\n", (char *)head->next->content);
//     return (0);
// }
