/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:27:45 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/26 15:45:32 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*output;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	output = (char *)malloc(len + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (i < len)
	{
		output[i] = f((unsigned int)i, s[i]);
		i++;
	}
	output[len] = '\0';
	return (output);
}

// char	ft_even_is_uppercase(unsigned int i, char c)
// {
// 	if (i % 2 == 0 && c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int main(void)
// {
// 	char *input = "Hello, my name is Tatiana";

// 	char *output = ft_strmapi(input, ft_even_is_uppercase);
// 	printf("%s\n", output);
// 	free(output);
// }
