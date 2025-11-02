/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:33:24 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/19 15:40:20 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (start < len && ft_strchr(set, s1[start]) != 0)
		start++;
	end = len;
	while (end > start && ft_strchr(set, s1[end - 1]) != 0)
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}

// int	main(void)
// {
// 	char	*str = ft_strtrim("--abc--def--", "-+");
// 	printf("%s\n", str);
// 	free(str);

// 	char	*str1 = ft_strtrim("  \tabc\n", " \n\t");
// 	printf("%s\n", str1);
// 	free(str1);

// 	char	*str2 = ft_strtrim("abc", "");
// 	printf("%s\n", str2);
// 	free(str2);

// 	char	*str3 = ft_strtrim("", "abc");
// 	printf("%s\n", str3);
// 	free(str3);

// 	char	*str4 = ft_strtrim("aaa", "abc");
// 	printf("%s\n", str4);
// 	free(str4);

// 	char	*str5 = ft_strtrim("abc", "def");
// 	printf("%s\n", str5);
// 	free(str5);

// 	return (0);
// }
