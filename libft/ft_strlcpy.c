/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:59:37 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/18 16:43:04 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	dst[10];
// 	char	src[] = "Hello, my name is Tatiana";
// 	size_t	dstsize = sizeof(dst);
// 	size_t	length;

// 	length = ft_strlcpy(dst, src, dstsize);
// 	printf("Needed length: %zu\n", length);
// 	printf("Output: %s\n", dst);
// 	return (0);
// }
