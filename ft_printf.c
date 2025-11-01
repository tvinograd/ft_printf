/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:48:31 by tvinogra          #+#    #+#             */
/*   Updated: 2025/11/01 12:42:21 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	count;
	int	i;

	count = 0;
	i = 0;
	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += ft_print_char(va_arg(args, int));
			else if (format[i] == 's')
				count += ft_print_str(va_arg(args, char *));
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
				count += ft_print_int(va_arg(args, int));
			else if (format[i] == 'u')
				count += ft_print_unsign_int(va_arg(args, unsigned int));
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}

int	main(void)
{
	int	my_result;
	int	printf_result;

	my_result = ft_printf("Char: %c\n", 'A');
	printf_result = printf("Char: %c\n", 'A');
	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);
	
	my_result = ft_printf("Chars: %c %c %c\n", 'A', 'B', 'C');
	printf_result = printf("Chars: %c %c %c\n", 'A', 'B', 'C');
	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);
	
	my_result = ft_printf("String: Hello, %s\n", "my name is Tatiana");
	printf_result = printf("String: Hello, %s\n", "my name is Tatiana");
	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);
	
	my_result = ft_printf("NULL: %s\n", NULL);
	printf_result = printf("NULL: %s\n", (char *)NULL);
	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);
	
	my_result = ft_printf("Percentage: %%\n");
	printf_result = printf("Percentage: %%\n");
	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);
	
	my_result = ft_printf("Decimal (base 10): %d\n", 42);
	printf_result = printf("Decimal (base 10): %d\n", 42);
	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);
	
	my_result = ft_printf("Integer (base 10): %i\n", 42);
	printf_result = printf("Integer (base 10): %i\n", 42);
	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);
	
	my_result = ft_printf("Unsigned decimal (base 10): %u\n", 42);
	printf_result = printf("Unsigned decimal (base 10): %u\n", 42);
	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);
	
	return (0);
}
