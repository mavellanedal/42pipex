/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:36:46 by mavellan          #+#    #+#             */
/*   Updated: 2025/03/12 11:43:19 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_puthex(unsigned long long num)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num >= 16)
	{
		ft_puthex(num / 16);
		ft_puthex(num % 16);
	}
	else
		write(1, &hex[num], 1);
}

int	ft_print_pointer(va_list args)
{
	unsigned long long	ptr;
	int					len;
	unsigned long long	tmp_ptr;

	ptr = (unsigned long long)va_arg(args, void *);
	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len += 2;
	ft_puthex(ptr);
	tmp_ptr = ptr;
	while (tmp_ptr > 0)
	{
		tmp_ptr /= 16;
		len ++;
	}
	return (len);
}
