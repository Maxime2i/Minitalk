/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:09:23 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/14 21:10:41 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include<unistd.h>
# include<stdlib.h>
# include<signal.h>
# include"ft_printf/ft_printf.h"

int		ft_strlen(char *str);
void	ft_error(void);
char	*if_s1(char s2);
char	*ft_strjoin(char *s1, char s2);
void	ft_serv(int signal, siginfo_t *siginfo, void *context);

#endif
