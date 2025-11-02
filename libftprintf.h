/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:46:02 by tvinogra          #+#    #+#             */
/*   Updated: 2025/11/02 13:56:22 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h> 
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_int(int n);
int	ft_print_unsign_int(unsigned int n);
int	ft_print_hex(unsigned int n, int uppercase);
int	ft_print_ptr(void *ptr);

#endif
