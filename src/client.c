/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:52:34 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/20 18:43:42 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void ft_error(int n)
{
	if (n == 1)
	{
		ft_printf("Error: Numero incorrecto de parametros\n");
		ft_printf("Ejecutar asi:\n./client <PID> <Mensaje>\n");
	}
	else if (n == 2)
		ft_printf("Error: Pid invalido\n");
	else if (n == 3)
		ft_printf("Error: Pid incorrecto\n");
	else if (n == 4)
		ft_printf("Error: Cadena vacia\n");
	exit(n);
}

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
		if (!sig_bits(str[count], pid))
			return (0);
		usleep(50);
		count++;
	}
	return (1);
}

int str_allnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(isdigit((int)(str[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		ft_error(1);
	if (str_allnum(argv[1]) == 0)
		ft_error(2);
	pid = ft_atoi(argv[1]);
	if (!sig_send(argv[2], pid))
		ft_error(3);
	
}
