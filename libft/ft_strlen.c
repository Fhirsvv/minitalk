/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:47:51 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/21 12:47:13 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "../include/so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str[0])
		return (-1);
	while (str[i])
	{
		i++;
	}
	return (i);
}
