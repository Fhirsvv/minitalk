/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:10:10 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/18 20:45:02 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>
#include <unistd.h>

void fun(int n, int pid)
{
	
}
void sig_handler(int sig, siginfo_t *info, void *str)
{
	(void)str;
	if (sig == SIGUSR1)
		fun(1, info->si_pid);
	else
		fun(0, info->si_pid);
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