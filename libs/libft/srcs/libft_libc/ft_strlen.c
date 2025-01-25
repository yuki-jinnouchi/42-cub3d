/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:17:59 by yjinnouc          #+#    #+#             */
/*   Updated: 2023/11/24 16:56:55 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

/*
#include <stdio.h> //for printf
// #include <unistd.h> //for write

int ft_strlen(char *str);

int main(int argc, char *argv[]){
    char *str;
    int n;

    if (argc == 2){
        n = ft_strlen(argv[1]);
        printf("%i\n", n);
        
    }else if (argc < 2){ //run test cases

        n = 0;
        printf("%d\n", n);

        str = "this is string";    
        n = ft_strlen(str);
        printf("String Length is %d\n", n);
        
    }else if (argc < 3){
        printf("%s\n", "too less args!");
    }else if (argc > 3){
        printf("%s\n", "too many args!");
    }
    return (0);
};
*/
