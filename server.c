/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:27:04 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/13 14:10:17 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int ft_strlen(char *str)
{
	int	i;

	i= 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*joined;
	int		i;

	if (!s1)
	{
		joined = malloc(sizeof(char) * 2);
		if (!joined)
			return(0);
		joined[0] = s2;
		joined[1] = '\0';
		return (joined);
	}
	if (!s2)
		return (0);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!joined)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i] = s2;
	i++;
	joined[i] = '\0';
	free(s1);
	return (joined);
}

void    ft_serv(int signal, siginfo_t *siginfo, void *context)
{
	static int  bit = 0;
	static int i = 0;
	static char *str;


	(void)context;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{	
		if (i == 0)
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
			kill(siginfo->si_pid, SIGUSR1);
		}
		if (i != 0)
			str = ft_strjoin(str, i);
		bit = 0;
		i = 0;
	}
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID = %d\n", pid);


	sig.sa_sigaction = ft_serv;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sig.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);

	while (argc == 1)
	{
		pause();
	}
	return (0);
}


