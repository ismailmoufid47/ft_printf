/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-mou <isel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:46:09 by isel-mou          #+#    #+#             */
/*   Updated: 2024/11/29 20:53:43 by isel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_nbrlen(long nbr, int hex, int hash)
{
	int	len;
	int	base;
	unsigned long n;

	len = 0;
	base = 10;
	n = nbr;
	if (nbr < 0 && !hex)
		n = -nbr;
	if (hex)
		base = 16;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	if (hash && hex && nbr)
		len += 0;
	if (!nbr)
		return (len + 1);
	if (nbr < 0 && !hex)
		len++;
	return (len);
}

int	ft_putnbr(long n, t_flags flags)
{
	int		len;
	int		written;
	char	padding_char;

	written = 0;
	len = ft_nbrlen(n, 0, 0);
	padding_char = ' ';
	if (flags.zero && !flags.minus && !flags.precision)
		padding_char = '0';
	if (flags.precision && flags.precision_value > len - (n < 0))
		len = flags.precision_value + (n < 0);
	if (flags.precision && n == 0 && flags.precision_value == 0)
		len = 0;
	if ((flags.space || flags.plus) && n >= 0)
		len++;
	while (!flags.minus && !flags.zero && flags.width-- > len)
		written += write(1, " ", 1);
	if (flags.space && !flags.plus && n >= 0)
		written += write(1, " ", 1);
	if (flags.plus && n >= 0)
		written += write(1, "+", 1);
	if (n < 0)
	{
		written += write(1, "-", 1);
		n = -n;
	}
	while (flags.width-- > len && !flags.minus && flags.zero)
		written += write(1, "0", 1);
	flags.precision_value += !n;
	while (flags.precision_value--> ft_nbrlen(n, 0, 0))
		written += write(1, "0", 1);
	if (!(flags.precision && !n && !flags.precision_value))
	{
		if (n > 9)
			written += ft_putnbr(n / 10, (t_flags){0});
		written += write(1, &(char){(n % 10) + '0'}, 1);
	}
	while (flags.width-- >= len && flags.minus)
		written += write(1, " ", 1);
	return (written);
}

int ft_putptr(unsigned long n, t_flags flags)
{
    int len;
    char padding_char;
	int written;
	
	written = 0;
	padding_char = ' ';
    len = ft_nbrlen(n, 1, 1) + (!n * 2) + (n > 0) * 2 ;
    if (!flags.minus && flags.width > len)
        while (flags.width-- > len)
            written += write(1, &padding_char, 1);
	if (flags.hash)
		written += write(1, "0x", 2);
    if (n >= 16)
        written += ft_putptr(n / 16, (t_flags){0});
    written += write(1, &"0123456789abcdef"[n % 16], 1);
    if (flags.minus && flags.width > len)
        while (flags.width-- > len)
            written += write(1, &padding_char, 1);
    return (written);
}

int ft_puthex(unsigned int n, int upper, t_flags flags)
{
	int len;
	int written;

	written = 0;
	len = ft_nbrlen(n, 1, flags.hash);
	
	if (flags.precision && n == 0 && flags.precision_value == 0)
		len = 0;
	if (flags.precision && flags.precision_value > len)
		len = flags.precision_value;
	if (flags.hash && n)
		len += 2;
	while (!flags.minus && !flags.zero && flags.width > len)
	{
		written += write(1, " ", 1);
		flags.width--;
	}
	if (upper && flags.hash && n)
		written += write(1, "0X", 2);
	else if (flags.hash && n)
		written += write(1, "0x", 2);
	while (!flags.minus && flags.zero && flags.width > len)
	{
		written += write(1, "0", 1);
		flags.width--;
	}
	while (flags.precision_value-- > ft_nbrlen(n, 1, 0) )
		written += write(1, "0", 1);
	if (n >= 16)
		written += ft_puthex(n / 16, upper, (t_flags){0});
	if (!(flags.precision && !n && flags.precision_value < 0))
	{
		if (upper)
			written += write(1, &"0123456789ABCDEF"[n % 16], 1);
		else
			written += write(1, &"0123456789abcdef"[n % 16], 1);
	}
	while (flags.minus && len < flags.width)
	{
		written += write(1, " ", 1);
		flags.width--;
	}
	return (written);
}


int	ft_putnbru(unsigned int n, t_flags flags)
{
	int		len;
	int		written;
	char	padding_char;

	written = 0;
	len = ft_nbrlen(n, 0, 0);
	padding_char = ' ';
	if (flags.zero && !flags.minus && !flags.precision)
		padding_char = '0';
	if (flags.precision && flags.precision_value > len - (n < 0))
		len = flags.precision_value + (n < 0);
	if (flags.precision && n == 0 && flags.precision_value == 0)
		len = 0;
	if ((flags.space || flags.plus) && n >= 0)
		len++;
	while (!flags.minus && !flags.zero && flags.width-- > len)
		written += write(1, " ", 1);
	if (flags.space && !flags.plus && n >= 0)
		written += write(1, " ", 1);
	if (flags.plus && n >= 0)
		written += write(1, "+", 1);
	if (n < 0)
	{
		written += write(1, "-", 1);
		n = -n;
	}
	while (flags.width-- > len && !flags.minus && flags.zero)
		written += write(1, "0", 1);
	flags.precision_value += !n;
	while (flags.precision_value--> ft_nbrlen(n, 0, 0))
		written += write(1, "0", 1);
	if (!(flags.precision && !n && !flags.precision_value))
	{
		if (n > 9)
			written += ft_putnbr(n / 10, (t_flags){0});
		written += write(1, &(char){(n % 10) + '0'}, 1);
	}
	while (flags.width-- >= len && flags.minus)
		written += write(1, " ", 1);
	return (written);
}
