/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:10:10 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/28 13:25:33 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>
#include <unistd.h>

int count = 0;
int i = 0;

void sig_handler(int sig)
{
	int susr2;

	susr2 = 0;
	if (sig == SIGUSR1)
	{
		i++;
		//ft_printf("%d\n", i);
	}	
	else if (sig == SIGUSR2 && i != 0)
	{
		susr2++;
		ft_printf("%c", i);
		i = 0;
	}
	else
		i = 0;
}
/*void sig_handler(int sig)
{
	static char buff[8];
	//static int count;
	int digit;
	int nb;
	int i;
ft_printf("count :%d\n", count);
ft_printf("la señal es: %d\n", sig);
	i = 0;
	nb = 0;
	//if (count == 0)
		//memcpy(buff, "00000000", 8);
	if (sig == SIGUSR2)
		buff[count] = '1';
	else
		buff[count] = '0';
	ft_printf("esto es despues del if sugusr\n");
	count++;
	if (count == 8)
	{
		while (i < 8)
		{
			digit = buff[i] - '0';
			nb = nb * 2 + digit;
			i++;
		}
		count = 0;
		//free(buff);
	}
	ft_printf("%c\n\n", nb);
}*/
/*void sig_handler(int sig)
{
	static char buff[8];
	static int count;
	int result;
	int i;

	i = 0;
	result = 0;
	if (count == 0)
		memcpy(buff, "00000000", 8);
	if (sig == SIGUSR2)
		buff[count] = '1';
	count++;
	if (count == 8)
		while (i < 8)
		{
			if (buff[i] == 1)
				result += 1 << (7 - i);
		}
	ft_printf("%d\n", result);
}*/


int main(void)
{
	signal(SIGUSR1, &sig_handler);
	signal(SIGUSR2, &sig_handler);

	ft_printf("PID:\t%d\n", getpid());
	while (1)
		pause();
	return (0);
}