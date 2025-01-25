/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:12 by yjinnouc          #+#    #+#             */
/*   Updated: 2023/11/24 16:20:37 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	length;
	char			*ptr;

	length = ft_strlen(s);
	ptr = (char *) malloc((length + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s, length);
	ptr[length] = 0;
	return (ptr);
}
