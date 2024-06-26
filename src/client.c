/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:52:34 by ecortes-          #+#    #+#             */
/*   Updated: 2024/04/03 18:37:45 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_error(int n)
{
	if (n == 1)
	{
		ft_printf("Error: Numero incorrecto de parametros\n");
		ft_printf("Ejecutar asi:\t./client <PID> <Mensaje>\n");
	}
	else if (n == 2)
		ft_printf("Error: Pid invalido\n");
	else if (n == 3)
		ft_printf("Error: Pid incorrecto\n");
	else if (n == 4)
		ft_printf("Error: Cadena vacia\n");
	else if (n == 5)
		ft_printf("Error: señal no enviada");
	exit(n);
}

int	sig_bits(char c_, int pid)
{
	int	i;
	int	c;

	i = 0;
	c = (int)c_;
	while (i < 7)
	{
		if (c % 2 == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(5);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error(5);
		}
		c /= 2;
		i++;
		usleep(300);
	}
	usleep(20);
	return (0);
}

static int	sig_send(char *str, int pid)
{
	size_t	count;

	count = 0;
	if (!ft_strlen(str))
		ft_error(4);
	while (str[count])
	{
		sig_bits(str[count], pid);
		count++;
	}
	return (1);
}

int	str_allnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit((int)(str[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_error(1);
	if (str_allnum(argv[1]) == 0)
		ft_error(2);
	pid = ft_atoi(argv[1]);
	if (!pid)
		ft_error(2);
	if (!sig_send(argv[2], pid))
		ft_error(3);
	return (0);
}
