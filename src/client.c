/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:52:34 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/18 21:35:19 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int sig_bits(char c, int pid)
{
	size_t i;
	int bit;
	char buff[8];

	i = 7;
	while (i >= 0)
	{
		bit = c & 1;
		if (bit == 1)
			buff[i] = '1';
		else
			buff[i] = '0';
		c >>= 1;
	}
	while (buff[++i])
	{
		if (buff[i] == '0')
			if (kill(pid, SIGUSR1) == -1)
				bit = 0;
		else
			if (kill(pid, SIGUSR2) == -1)
				bit = 0;
		usleep(50);
	}
	return (bit);
}

static int sig_send(char *str, int pid)
{
	size_t count;

	count = 0;
	if(!strlen(str))
		ft_error(4);
	while (str[count])
	{
		if (sig_bits(str[count], pid))
			return (0);
		usleep(50);
		count++;
	}
	
}

int main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		ft_error(1);
	if (!ft_isalnum(argv[1]))
		ft_error(2);
	pid = ft_atoi(argv[1]);
	if (!sig_send(argv[2], pid))
		ft_error(3);
	
}
