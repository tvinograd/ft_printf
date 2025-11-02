/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:38:33 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/28 16:37:10 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long number)
{
	int	len;

	if (number == 0)
		return (1);
	len = 0;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number > 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	number;
	int		len;
	char	*str;

	number = (long)n;
	len = ft_intlen(number);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	while (number > 0)
	{
		str[--len] = (char)('0' + (number % 10));
		number /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_itoa(-123);
// 	printf("%s\n", str);
// 	free (str);
// 	return (0);
// }
