/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:56:37 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/27 10:00:52 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((size_t)start >= slen)
		return (ft_strdup(""));
	if (len > slen - (size_t)start)
		len = slen - (size_t)start;
	sub = (char *)malloc((len + 1));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

// int	main(void)
// {
// 	char const		*s = "Hello, my name is Tatiana";
// 	unsigned int	start = 7;
// 	size_t			len = 7;
// 	char			*sub;

// 	sub = ft_substr(s, start, len);
// 	printf("%s\n", sub);
// 	free(sub);
// 	return (0);
// }
