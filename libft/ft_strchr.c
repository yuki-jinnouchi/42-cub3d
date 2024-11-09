/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:59:02 by hakobori          #+#    #+#             */
/*   Updated: 2024/04/23 23:06:35 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	char	c2;

	c2 = (char)c;
	s1 = (char *)s;
	while (*s1 && *s1 != c2)
		s1++;
	if (*s1 == c2)
		return (s1);
	return (NULL);
}

// #include<stdio.h>
// int main()
// {
// 	char str[]="abcde";
// 	printf("%s\n",strchr(str,'l'+256));
// }