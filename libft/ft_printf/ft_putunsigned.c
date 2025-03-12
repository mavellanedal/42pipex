/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:28:51 by mavellan          #+#    #+#             */
/*   Updated: 2025/03/12 11:43:10 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	char	digit;

	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}
