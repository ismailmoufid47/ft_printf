/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-mou <isel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:15:20 by isel-mou          #+#    #+#             */
/*   Updated: 2024/11/29 13:54:10 by isel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	minus;
	int	width;
	int	precision;
	int	precision_value;
	int	zero;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

int ft_putptr(unsigned long n, t_flags flags);
int ft_puthex(unsigned int n, int upper, t_flags flags);
int ft_putnbru(unsigned int n, t_flags flags);
int	ft_printf(const char *format, ...);
int	ft_putchar(char c, t_flags flags);
int	ft_putstr(char *str, t_flags flags);
int	ft_putnbr(long n, t_flags flags);
int	printspace(int width, t_flags flags);
int	ft_atoi(char **format);

#endif