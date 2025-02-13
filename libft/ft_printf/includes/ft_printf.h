/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:15:55 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/11 21:15:45 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>


int		ft_printf(const char *format, ...);
int		ft_print_string(va_list args);
int		ft_print_char(va_list args);
int		ft_print_int(va_list args);
void	ft_putnbr_unsigned(unsigned int n);
int		ft_print_unsigned(va_list args);
int		ft_check_format(va_list args, const char *format);
int		ft_print_hex(va_list args, char format);
void	ft_putnbr_base(unsigned long long nbr, char *base);
int		ft_print_pointer(va_list args);
void	ft_puthex(unsigned long long num);

#endif
