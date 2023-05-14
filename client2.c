/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:12:09 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/14 21:12:32 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"client.h"

void	ft_error(int nb)
{
	if (nb == 1)
		ft_printf("Erreur\n");
	if (nb == 2)
		ft_printf("Erreur : mauvais arguments\n");
	if (nb == 3)
		ft_printf("Erreur : chaine vide\n");
	if (nb == 4)
		ft_printf("Erreur : mauvais pid\n");
	exit(0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
