# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 15:20:13 by hakobori          #+#    #+#              #
#    Updated: 2024/11/09 15:24:55 by hakobori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
RCS_DIR	 = ./srcs/
BILT_DIR     = ./builtin/
INCLUDE_DIR  = ./includes/
LIBFT_DIR 	 = ./libft/
CFLAGS 		 = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(RL_INC_DIR)
OBJS 		 = $(SRCS:.c=.o)
LIBFT 		 = $(LIBFT_DIR)libft.a

SRCS 		 = $(SRCS_DIR)main.c \

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re