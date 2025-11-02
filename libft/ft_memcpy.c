/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:13:58 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/18 16:42:43 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}

// int	main(void)
// {
// 	char	src[] = "I love";
// 	char	dst[] = "I hate programming";
// 	void *d = ft_memcpy(dst, src, 6);
// 	printf("%s\n", dst);
// 	return (0);
// }
