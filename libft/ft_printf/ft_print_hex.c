/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:50:53 by mavellan          #+#    #+#             */
/*   Updated: 2025/03/12 11:43:25 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_putnbr_base(unsigned long long nbr, char *base)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
}

int	ft_print_hex(va_list args, char format)
{
	unsigned int	num;
	int				len;
	char			*base;
	unsigned int	temp;

	num = va_arg(args, unsigned int);
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	len = 0;
	if (num == 0)
		len += write(1, "0", 1);
	else
		ft_putnbr_base(num, base);
	temp = num;
	while (temp)
	{
		temp /= 16;
		len++;
	}
	return (len);
}
