/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-mou <isel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:25:46 by isel-mou          #+#    #+#             */
/*   Updated: 2024/11/25 18:24:48 by isel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags flags)
{
	int	written;

	written = 1;
	while (flags.width-- > 1 && !flags.minus)
		written += write(1,  " ", 1);
	write(1, &c, 1);
	while (flags.width-- > 0 && flags.minus)
		written += write(1, " ", 1);
	return (written);
}
