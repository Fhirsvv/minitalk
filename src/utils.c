/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:54:23 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/18 21:07:11 by ecortes-         ###   ########.fr       */
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
	else if (n == 5)
		ft_printf("Error\nMap is not a rectangle! \n");
	exit(n);
}
