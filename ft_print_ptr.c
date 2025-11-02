/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 23:06:56 by tvinogra          #+#    #+#             */
/*   Updated: 2025/11/02 15:48:56 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_put_ptr(unsigned long n)
{
	char	*hex_digits;
	int		count;
	
	hex_digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count = ft_put_ptr(n / 16);
		if (count == -1)
			return (-1);
		if (ft_put_ptr(n % 16) == -1)
			return (-1);
		count += 1;
	}
	else
	{
		if (write(1, &hex_digits[n], 1) == -1)
			return (-1);
		count = 1;
	}
	return(count);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	int				len;

	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	address = (unsigned long)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = ft_put_ptr(address);
	if (len == -1)
		return (-1);
	return (2 + len);
}

// int	main(void)
// {	
// 	int result = printf("%p\n", NULL);
// 	printf("Returned: %d\n", result);
// 	return (0);
// }
