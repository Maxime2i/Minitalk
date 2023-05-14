/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:52:40 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/14 21:32:56 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include<unistd.h>
# include<stdlib.h>
# include<signal.h>
# include"ft_printf/ft_printf.h"

void	ft_error(int nb);
int		ft_strlen(char *str);
int		is_digit(char *str);
void	ft_envoi_car(pid_t pid, char c);
int		ft_atoi(const char *nptr);
void	ft_attente(int signal, siginfo_t *siginfo, void *context);

#endif
