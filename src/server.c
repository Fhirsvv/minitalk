/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:10:10 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/24 12:09:25 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <math.h>

int	ft_pow (int nb, int exp)
{
	if (exp == 0)
		return (1);
	else if (exp == 1)
		return (nb);
	else
		return (nb * ft_pow(nb, exp - 1));
}

int to_decimal(char *str)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (i < 7)
	{
		nb = nb + (str[i] - '0') * ft_pow(2, 6 - i);
		i++;
	}
	return (nb);
}
void sig_handler(int sig)
{
	static char	str[7];
	static int	i;

	if (sig == SIGUSR1)	
	{
		str[6 - i] = '0';
	}
	else if (sig == SIGUSR2)
	{
		str[6 - i] = '1';
	}
	i++;
	if (i > 6)
	{
		ft_printf("%c", to_decimal(str));
		i = 0;
		ft_bzero(str, 7);
	}
	
}

int main(void)
{
	signal(SIGUSR1, &sig_handler);
	signal(SIGUSR2, &sig_handler);
	ft_printf("PID:\t%d\n", getpid());
	while (1)
		pause();
	return (0);
}