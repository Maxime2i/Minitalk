/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:52:50 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/14 21:06:51 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"client.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	rep;
	int	i;
	int	sign;

	i = 0;
	rep = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		rep = rep * 10 + (nptr[i] - '0');
		i++;
	}
	return (rep * sign);
}

void	ft_envoi_car(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(1);
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				ft_error(1);
		bit++;
		usleep(5000);
	}
}

void	ft_attente(int signal, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (signal == SIGUSR1)
		ft_printf("Confirmation\n");
}

int	main(int ac, char **av)
{
	int					i;
	struct sigaction	sa;

	i = 0;
	if (ac != 3)
		ft_error(2);
	if (!av[2][0])
		ft_error(3);
	if (is_digit(av[1]) == 1 || (ft_strlen(av[1]) != 6 && ft_strlen(av[1]) != 5))
		ft_error(4);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_sigaction = ft_attente;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error(1);
	while (av[2][i])
		ft_envoi_car(atoi(av[1]), av[2][i++]);
	ft_envoi_car(atoi(av[1]), '\n');
	ft_envoi_car(atoi(av[1]), '\0');
	return (0);
}
