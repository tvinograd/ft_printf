/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:22:13 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/18 16:40:59 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

// int	main(void)
// {
// 	char	input[5] = "Hello";
// 	ft_bzero(input, 3);
// 	printf("%s\n", input);
// 	printf("%c%c%c%c%c\n", input[0], input[1], input[2], input[3], input[4]);
// 	return (0);
// }
