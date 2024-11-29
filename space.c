/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-mou <isel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:33:51 by isel-mou          #+#    #+#             */
/*   Updated: 2024/11/25 18:14:44 by isel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	printspace(int nbr)
{
	int	total_written;

	if (nbr < 0)
		nbr = 0;
	total_written = 0;
	while (nbr-- > 0)
		total_written += write(1, " ", 1);
	return (total_written);
}