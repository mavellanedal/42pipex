/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:00:21 by mavellan          #+#    #+#             */
/*   Updated: 2025/03/12 11:43:13 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_print_unsigned(va_list args)
{
	unsigned int	num;
	int				len;
	unsigned int	tmp;

	num = va_arg(args, unsigned int);
	tmp = num;
	len = 0;
	if (num == 0)
		len = 1;
	else
	{
		while (tmp > 0)
		{
			tmp /= 10;
			len++;
		}
	}
	ft_putnbr_unsigned(num);
	return (len);
}
