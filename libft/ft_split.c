/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:08:17 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/28 16:38:58 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_strndup(char const *s, size_t len)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	ft_freesplit(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	arr = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		arr[j] = ft_strndup(s + i, ft_wordlen(s + i, c));
		if (!arr[j++])
			return (ft_freesplit(arr, j - 1), (char **) NULL);
		i += ft_wordlen(s + i, c);
	}
	arr[j] = NULL;
	return (arr);
}

// int	main(void)
// {
// 	char *input = "Hello, my name is Tatiana ";
// 	char split = ' ';
// 	size_t	len;
// 	char *dst;
// 	char **arr;
// 	size_t i;

// printf("Checking ft_wordcount. Amount of words: %zu\n",
// 	ft_wordcount(input, split));
// printf("Checking ft_wordlen. Length of first word: %zu\n",
// 	ft_wordlen(input, split));

// 	len = ft_strlen(input);
// 	dst = ft_strndup(input, len);
// 	printf("Checking ft_strndup. String copy: %s\n", dst);
// 	free(dst);

// 	printf("Checking ft_split. Result: ");
// 	arr = ft_split(input, split);
// 	i = 0;
// 	while (arr[i])
// 	{
// 		printf("[%s]", arr[i]);
// 		i++;
// 	}
// 	ft_freesplit(arr, i);
// 	return (0);
// }
