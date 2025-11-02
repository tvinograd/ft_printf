/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:42:49 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/27 12:14:39 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// int main(void)
// {
// 	t_list *head = NULL;
// 	printf("%d\n", ft_lstsize(head));

// 	head = ft_lstnew("cd");
//     printf("%d ", ft_lstsize(head));
// 	printf("[%s]\n", (char *)head->content);

// 	ft_lstadd_front(&head, ft_lstnew("ab"));
//     printf("%d ", ft_lstsize(head));
// 	printf("[%s]", (char *)head->content);
// 	printf("[%s]\n", (char *)head->next->content);
// 	return (0);
// }
