/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:52:40 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/13 15:13:10 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include"ft_printf/ft_printf.h"

int ft_strlen(char *str);
char	*ft_strjoin(char *s1, char s2);
void    ft_envoi_car(pid_t pid, char c);
void    ft_serv(int signal, siginfo_t *info, void *context);
int	ft_atoi(const char *nptr);

#endif
