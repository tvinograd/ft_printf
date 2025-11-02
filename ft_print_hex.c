/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:59:29 by tvinogra          #+#    #+#             */
/*   Updated: 2025/11/02 16:21:59 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*ft_hex_to_str(unsigned int n, int uppercase)
{
	char	*hex_digits;
	char	*str;
	int		len;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	len = ft_hex_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = hex_digits[n % 16];
		n /= 16;
	}
	return (str);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	char	*str;
	int		len;

	str = ft_hex_to_str(n, uppercase);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}
