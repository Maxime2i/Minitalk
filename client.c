/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:52:50 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/13 14:11:13 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

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

void    ft_envoi_car(pid_t pid, char c)
{
	int  bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
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

int main(int ac, char **av)
{
	pid_t pid;
	int i;
	struct sigaction	sa;

	i = 0;

	if (ac != 3)
	{
		ft_printf("mauvais argument !");
		return (1);
	}

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_sigaction = ft_attente;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		ft_envoi_car(pid, av[2][i]);
		i++;
	}
	ft_envoi_car(pid, '\n');
	ft_envoi_car(pid, '\0');
	


	return(0);
}
