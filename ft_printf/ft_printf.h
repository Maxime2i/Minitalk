/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:55:24 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/18 14:14:17 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_format(va_list arg, const char format);
char	*ft_uitoa(unsigned int n);
void	ft_putstr(char *str);
void	ft_putptr(unsigned long long num);
void	ft_puthex(unsigned int num, const char format);
int		ft_ptrlen(unsigned long long num);
int		ft_printunsigned(unsigned int n);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printpercent(void);
int		ft_printnbr(int n);
int		ft_printhex(unsigned int num, const char format);
int		ft_printchar(int c);
int		ft_num_len(unsigned	int num);
int		ft_hex_len(unsigned	int num);
char	*ft_itoa(int nb);
int		ft_intlen(long nb);
void	ft_putchar(char c);
char	*ft_ifzero(void);
long	ft_ifinfzero(char *str, long n);

#endif
