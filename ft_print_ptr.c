/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 23:06:56 by tvinogra          #+#    #+#             */
/*   Updated: 2025/11/02 13:53:52 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_ptr_len(unsigned long n)
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

static void	ft_put_ptr(unsigned long n)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
		write(1, &hex_digits[n], 1);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	int				len;

	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	len = 2;
	ft_put_ptr(address);
	len += ft_ptr_len(address);
	return (len);
}

// int	main(void)
// {	
// 	int result = printf("%p\n", NULL);
// 	printf("Returned: %d\n", result);
// 	return (0);
// }
