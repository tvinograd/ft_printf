/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:15:28 by tvinogra          #+#    #+#             */
/*   Updated: 2025/11/02 15:11:21 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_str(char *str)
{
	int	len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}

// int	main(void)
// {	
// 	int result = printf("String: %s\n", (char *)NULL);
// 	printf("Returned: %d\n", result);
// 	return (0);
// }
