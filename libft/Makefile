CC 		= cc
CFLAGS  = -Wall -Wextra -Werror
NAME 	= libft.a
SRC 	= ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
	  	  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_printf.c \
		  ft_treat_cs.c \
		  ft_treat_di.c \
		  ft_treat_phex.c \
		  ft_treat_u.c \
		  ft_atol.c
SRC_2   = ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstsize.c \
		  ft_lstiter.c \
		  ft_lstmap.c
OBJS    = $(SRC:%.c=%.o)
OBJS_2  = $(SRC_2:%.c=%.o)
INCLUDE = libft.h

ifdef BONUS
	OBJS += $(OBJS_2)
endif

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : $(OBJS)
	make all BONUS=1

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_2)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus