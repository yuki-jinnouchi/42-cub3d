#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include"./libs/libft/libft.h"
#include"./libs/get_next_line/get_next_line.h"

#define TRUE 1
#define FALSE 0

typedef struct s_map {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	int		width;
	int		height;
	char	**structure;
}			t_map;


#endif