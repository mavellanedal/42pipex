/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:55:41 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/19 17:05:28 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (len > i && big[i])
	{
		j = 0;
		while (len > i + j && big[i + j] == little[j] && big[i + j])
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (0);
}
