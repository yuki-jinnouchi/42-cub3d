/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:42:46 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/03 21:44:33 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define READ_ERROR -2

char	*get_next_line(int fd);

#endif
