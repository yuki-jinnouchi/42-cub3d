/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:59:50 by hakobori          #+#    #+#             */
/*   Updated: 2024/04/19 13:45:42 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	j = 0;
	i = start;
	while (j < len && s[i])
		result[j++] = s[i++];
	result[j] = '\0';
	return (result);
}
