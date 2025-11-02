/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:32:57 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/18 16:43:00 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = 0;
	slen = 0;
	i = 0;
	while (dlen < dstsize && dst[dlen] != '\0')
		dlen++;
	while (src[slen] != '\0')
		slen++;
	if (dlen == dstsize)
		return (dstsize + slen);
	while (i + dlen + 1 < dstsize && src[i] != '\0')
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

// int	main(void)
// {
// 	char dst[] = "Hello";
// 	const char src[] = ", my name is Tatiana";
// 	size_t dstsize = 10;

// 	printf("Expected size: %zu\n", ft_strlcat(dst, src, dstsize));
// 	printf("Output according to the given size: %s\n", dst);
// 	return(0);
// }
