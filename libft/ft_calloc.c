/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:38:49 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/24 12:05:23 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*ptr;
	size_t	i;

	if (num >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	ptr = malloc(num * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	if (ptr != NULL)
	{
		i = 0;
		while (i < num * size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
