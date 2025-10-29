/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:48:31 by tvinogra          #+#    #+#             */
/*   Updated: 2025/10/29 15:20:32 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == 'c')
			ft_print_char();
		else if (*format == 's')
			ft_print_str();
		else if (*format == 'p')
			ft_print_address_hex();
		else if (*format == 'd' || 'i')
			ft_print_int();
		else if (*format == 'u')
			ft_print_unsign_int();
		else if (*format == 'x' || 'X')
			ft_print_num_hex();
		else if (*format == '%')
			ft_print_char();
		format++;
	}
	va_end(args);
}
