/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:03:32 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/18 16:45:46 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

// int	main(void)
// {
// 	char *str;
// 	int i = 5;
// 	int j = 2;
// 	int z = i * j;

// 	str = ft_calloc(i, j);
// 	for(int i = 0; i < z; i++)
// 	{
// 		printf ("[%2d] ", str[i]);
// 	}
// 	printf("\n");
// 	ft_memset(str, 'A', z);
// 	str[5] = 10;
// 	for(int i = 0; i < z; i++)
// 	{
// 		printf ("[%2d] ", str[i]);
// 	}
// 	printf("\n");
// 	free(str);
// 	return(0);
// }
