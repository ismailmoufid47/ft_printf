/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-mou <isel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:33:09 by isel-mou          #+#    #+#             */
/*   Updated: 2024/11/29 15:47:25 by isel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

#include <stdio.h>

int	ft_putstr(char *str, t_flags flags)
{
	int	written;
	int	len;

	written = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.precision && flags.precision_value < len)
		len = flags.precision_value;
	while (flags.width-- > len && !flags.minus)
		written += write(1, " ", 1);
	written += write(1, str, len);
	while (flags.width-- >= len && flags.minus)
		written += write(1, " ", 1);
	return (written);
}
