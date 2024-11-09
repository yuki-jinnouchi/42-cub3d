/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:58:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/04/22 11:24:41 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	result = malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}
