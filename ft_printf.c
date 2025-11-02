/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:48:31 by tvinogra          #+#    #+#             */
/*   Updated: 2025/11/02 16:51:26 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_conversion(char specifier, va_list args)
{
	int	result;

	result = 0;
	if (specifier == 'c')
		result = ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		result = ft_print_str(va_arg(args, char *));
	else if (specifier == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		result = 1;
	}
	else if (specifier == 'd' || specifier == 'i')
		result = ft_print_int(va_arg(args, int));
	else if (specifier == 'u')
		result = ft_print_unsign_int(va_arg(args, unsigned int));
	else if (specifier == 'x')
		result = ft_print_hex(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		result = ft_print_hex(va_arg(args, unsigned int), 1);
	else if (specifier == 'p')
		result = ft_print_ptr(va_arg(args, void *));
	return (result);
}

static int	ft_format(const char *format, int *i, va_list args)
{
	int	result;

	if (format[*i] == '%' && format[++(*i)])
	{
		result = ft_conversion(format[*i], args);
		if (result == -1)
			return (-1);
		return (result);
	}
	else
	{
		if (write(1, &format[*i], 1) == -1)
			return (-1);
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		result;

	if (format == NULL)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		result = ft_format(format, &i, args);
		if (result == -1)
			return (-1);
		count += result;
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	my_result;
// 	int	printf_result;

// 	my_result = ft_printf("Char: %c\n", 'A');
// 	printf_result = printf("Char: %c\n", 'A');
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("Chars: %c %c %c\n", 'A', 'B', 'C');
// 	printf_result = printf("Chars: %c %c %c\n", 'A', 'B', 'C');
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("String: Hello, %s\n", "my name is Tatiana");
// 	printf_result = printf("String: Hello, %s\n", "my name is Tatiana");
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	char	*null = NULL;
// 	my_result = ft_printf("NULL: %s\n", null);
// 	printf_result = printf("NULL: %s\n", null);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("Empty string: %s\n", "");
// 	printf_result = printf("Empty string: %s\n", "");
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("Percentage: %%\n");
// 	printf_result = printf("Percentage: %%\n");
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("Decimal (base 10): %d\n", 42);
// 	printf_result = printf("Decimal (base 10): %d\n", 42);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("INT_MIN: %d\n", INT_MIN);
// 	printf_result = printf("INT_MIN: %d\n", INT_MIN);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("INT_MAX: %d\n", INT_MAX);
// 	printf_result = printf("INT_MAX: %d\n", INT_MAX);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("Integer (base 10): %i\n", 42);
// 	printf_result = printf("Integer (base 10): %i\n", 42);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("Unsigned decimal (base 10): %u\n", 42);
// 	printf_result = printf("Unsigned decimal (base 10): %u\n", 42);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("UINT_MAX: %u\n", UINT_MAX);
// 	printf_result = printf("UINT_MAX: %u\n", UINT_MAX);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("Hexidecimal lowercase: %x\n", 42);
// 	printf_result = printf("Hexidecimal lowercase: %x\n", 42);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("Hexidecimal uppercase: %X\n", 42);
// 	printf_result = printf("Hexidecimal uppercase: %X\n", 42);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("Hexidecimal uppercase: %X\n", 42);
// 	printf_result = printf("Hexidecimal uppercase: %X\n", 42);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	char	*str1 = "Hello";
// 	my_result = ft_printf("Address: %p\n", str1);
// 	printf_result = printf("Address: %p\n", (void *)str1);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("NULL pointer: %p\n", NULL);
// 	printf_result = printf("NULL pointer: %p\n", NULL);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("%k\n", NULL);
// 	printf_result = 1; //printf("%k\n", NULL);
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	my_result = ft_printf("%");
// 	printf_result = 1;
// 	printf("My count: %d, Printf count: %d\n\n", my_result, printf_result);

// 	return (0);
// }
