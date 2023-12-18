/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:10:10 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/18 22:05:51 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>
#include <unistd.h>

void sig_handler(int sig)
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
}


int main(void)
{
	/*struct sigaction sa;

	sa.sa_flags = 0;
	sa.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);*/
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);

	ft_printf("PID:\t%d\n", getpid());
	while (1)
		pause();
	return (0);
}