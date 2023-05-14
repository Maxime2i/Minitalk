/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:27:04 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/14 21:04:56 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"server.h"

char	*if_s1(char s2)
{
	char	*joined;

	joined = malloc(sizeof(char) * 2);
	if (!joined)
		return (0);
	joined[0] = s2;
	joined[1] = '\0';
	return (joined);
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*joined;
	int		i;

	if (!s1)
	{
		joined = if_s1(s2);
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
	joined[i++] = s2;
	joined[i] = '\0';
	free(s1);
	return (joined);
}

void	ft_serv(int signal, siginfo_t *siginfo, void *context)
{
	static int		bit = 0;
	static int		i = 0;
	static char		*str;

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
			if (kill(siginfo->si_pid, SIGUSR1) == -1)
				ft_error();
		}
		if (i != 0)
			str = ft_strjoin(str, i);
		bit = 0;
		i = 0;
	}
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		ft_error();
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
		ft_error();
	pid = getpid();
	ft_printf("PID = %d\n", pid);
	sig.sa_sigaction = ft_serv;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		ft_error();
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		ft_error();
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
