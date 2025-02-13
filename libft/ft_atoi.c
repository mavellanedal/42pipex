/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:54:28 by mavellan          #+#    #+#             */
/*   Updated: 2024/12/12 15:27:45 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			n *= -1;
		i++;
	}
	while ((nptr[i] != '\0') && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * n);
}
