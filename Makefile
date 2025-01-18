# $@: name of the target file (one before colon)
# $<: name of first prerequisite file (first one after colon)
# $^: names of all prerequisite files (space separated)
# $*: stem (bit which matches the % wildcard in rule definition)
#
# VAR = val: Normal setting - values within are recursively expand when var used.
# VAR := val: Setting of var with simple expansion of values inside - values are expanded at decl time.
# VAR ?= val: Set var only if it doesn't have a value.
# VAR += val: Append val to existing value (or set if var didn't exist).

#===============================================
# Output File
NAME = 		$(OUTPUT_DIR)/cub3D
OUTPUT_DIR := 	.

# Directories
INCLUDES_DIR =		incl
SOURCES_ROOT_DIR =	srcs
SOURCES_DIR =		$(SOURCES_ROOT_DIR)
SOURCES_DIR +=		$(shell find $(SOURCES_ROOT_DIR) -mindepth 1 -type d)
OBJECTS_ROOT_DIR =	objs
OBJECTS_DIR :=		$(patsubst $(SOURCES_ROOT_DIR)%,$(OBJECTS_ROOT_DIR)%,$(SOURCES_DIR))

# Files
HEADERS =		$(wildcard $(INCLUDES_DIR)/*.h)
SOURCES =		$(shell find $(SOURCES_ROOT_DIR) -name "*.c")
OBJECTS =		$(patsubst $(SOURCES_ROOT_DIR)/%.c,$(OBJECTS_ROOT_DIR)/%.o,$(SOURCES))

#-----------------------------------------------
# Libraries
## LIBFT
LIBFT_DIR =				libs/libft
LIBFT_INCLUDES_DIR =	$(LIBFT_DIR)/incl
LIBFT =					$(LIBFT_DIR)/libft.a
## LIBMLX
OS = $(shell uname)
ifeq ($(OS), Darwin)
	OS :=					__APPLE__
	LIBMLX_DIR = 			libs/minilibx_opengl_20191021
	LIBMLX_INCLUDES_DIR =	$(LIBMLX_DIR)
	LIBMLX =				$(LIBMLX_DIR)/libmlx.a
	LIBMLX_LL_FLAGS = 		-lft -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(OS), Linux)
	OS =					__linux__
	LIBMLX_DIR = 			libs/minilibx-linux
	LIBMLX_INCLUDES_DIR =	$(LIBMLX_DIR)
	LIBMLX =				$(LIBMLX_DIR)/libmlx_Linux.a
	LIBMLX_LL_FLAGS =		-lft -lmlx_Linux -lXext -lX11 -lm -lz
endif
LIBX_LINUX_URL = 			https://github.com/42Paris/minilibx-linux.git

# BONUS_SOURCES = \
# 	$(wildcard $(BONUS_DIR)/*.c)
# BONUS_OBJECTS = 	$(BONUS_SOURCES:.c=.o)
# BONUS_OBJECTS += 	$(OBJECTS)

#-----------------------------------------------
# Compiler & Flags
CC = 		cc
W3_FLAGS =	-Wall -Wextra -Werror
UI_FLAGS =	-I$(INCLUDES_DIR) -I$(LIBFT_INCLUDES_DIR) -I$(LIBMLX_INCLUDES_DIR) -D$(OS)
UL_FLAGS =	-L$(LIBFT_DIR) -L$(LIBMLX_DIR)
LL_FLAGS =	$(LIBMLX_LL_FLAGS)
VG_FLAGS =	-g -fsanitize=address -fsanitize=undefined

#===============================================
# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#===============================================
# Phony targets
.PHONY: all clean fclean re
.PHONY: libft libmlx bonus
.PHONY: aclean ac rec ar test colors

#===============================================
# Link Targets
all: $(NAME)
$(NAME): $(OBJECTS)
	@printf "\r$(GREEN)[%2d/%2d]$(DEF_COLOR) All files compiled! Linking $(CYAN)$(NAME)$(DEF_COLOR)\033[K" \
		"$$(find $(SOURCES_ROOT_DIR) -type f | wc -l)" "$$(find $(SOURCES_ROOT_DIR) -type f | wc -l)"
	@$(CC) $(UI_FLAGS) $(UL_FLAGS) $^ -o $@ $(LL_FLAGS) $(VG_FLAGS)
	@echo "\n$(GREEN)<-------- $(NAME) linked. -------------------------->$(DEF_COLOR)"
	@chmod 777 $(NAME)
	@echo "$(GREEN)<-------- $(NAME) permission changed. -------------->$(DEF_COLOR)"
	@echo "$(CYAN)######### $(NAME) compile finished! #################$(DEF_COLOR)"

#-----------------------------------------------
# Compile Targets
$(OBJECTS_ROOT_DIR)/%.o: $(SOURCES_ROOT_DIR)/%.c | $(OBJECTS_DIR) libmlx libft
	@printf "\r$(GREEN)[%2d/%2d]$(DEF_COLOR) Compiling objects: $(CYAN)%s$(DEF_COLOR)\033[K" \
		"$$(find $(OBJECTS_ROOT_DIR) -type f | wc -l)" "$$(find $(SOURCES_ROOT_DIR) -type f | wc -l)" "$<"
	@$(CC) $(W3_FLAGS) $(UI_FLAGS) -c $< -o $@ $(VG_FLAGS)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

#-----------------------------------------------
# Clean Targets
clean:
	@rm -f $(OBJECTS)
	@rm -rf $(OBJECTS_DIR)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(LIBMLX_DIR) clean > /dev/null || make
	@echo "$(GRAY)<-------- $(NAME) object files cleaned. ------------>$(DEF_COLOR)"

fclean: clean
	@rm -rf $(OUTPUT_DIR)/$(NAME)
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(GRAY)<-------- $(NAME) .a and executable files cleaned. ->$(DEF_COLOR)"

re: fclean all

#-----------------------------------------------
# libft
libft: $(LIBFT)
$(LIBFT):
	@make -sC $(LIBFT_DIR) > /dev/null || make
	@echo "$(CYAN)<-------- make libft done. ------------------------->$(DEF_COLOR)"

# minilibx
libmlx: $(LIBMLX)
$(LIBMLX): $(LIBMLX_DIR)
	@make -sC $(LIBMLX_DIR) > /dev/null || make
	@echo "$(CYAN)<-------- make minilibx done ----------------------->$(DEF_COLOR)"
$(LIBMLX_DIR):
	@echo "Cloning Minilibx Linux repository..."
	@git clone $(LIBX_LINUX_URL) $(LIBMLX_DIR)

#-----------------------------------------------
# # bonus
# bonus: all $(BONUS_OBJECTS)
# 	ar rcs $(NAME) $(BONUS_OBJECTS)

#-----------------------------------------------
# non mandatory
aclean: all clean
ac: all clean
rec: re clean
ar:
	ar rcs $(OUTPUT_DIR)/$(NAME) $(OBJECTS)
test:
	@echo "OUTPUT_DIR:          $(OUTPUT_DIR)"
	@echo "NAME:                $(NAME)"
	@echo "-----------------------------"
	@echo "INCLUDES_DIR:        $(INCLUDES_DIR)"
	@echo "SOURCES_ROOT_DIR:    $(SOURCES_ROOT_DIR)"
	@echo "SOURCES_DIR:\n	$(SOURCES_DIR)"
	@echo "OBJECTS_ROOT_DIR:    $(OBJECTS_ROOT_DIR)"
	@echo "OBJECTS_DIR:\n	$(OBJECTS_DIR)"
	@echo "-----------------------------"
	@echo "HEADERS:             $(HEADERS)"
	@echo "SOURCES:\n	$(SOURCES)"
	@echo "OBJECTS:\n	$(OBJECTS)"
	@echo "-----------------------------"
	@echo "OS:                  $(OS)"
	@echo "LIBMLX_DIR:          $(LIBMLX_DIR)"
	@echo "LIBMLX:              $(LIBMLX)"
	@echo "LIBMLX_INCLUDES_DIR: $(LIBMLX_INCLUDES_DIR)"
	@echo "LIBMLX_LL_FLAGS:     $(LIBMLX_LL_FLAGS)"
	@echo "LIBFT_DIR:           $(LIBFT_DIR)"
	@echo "LIBFT:               $(LIBFT)"
	@echo "LIBFT_INCLUDES_DIR:  $(LIBFT_INCLUDES_DIR)"
	@echo "LIBX_LINUX_URL:      $(LIBX_LINUX_URL)"
colors:
	@echo "$(DEF_COLOR)DEF_COLOR$(DEF_COLOR)"
	@echo "$(GRAY)GRAY$(DEF_COLOR)"
	@echo "$(RED)RED$(DEF_COLOR)"
	@echo "$(GREEN)GREEN$(DEF_COLOR)"
	@echo "$(YELLOW)YELLOW$(DEF_COLOR)"
	@echo "$(BLUE)BLUE$(DEF_COLOR)"
	@echo "$(MAGENTA)MAGENTA$(DEF_COLOR)"
	@echo "$(CYAN)CYAN$(DEF_COLOR)"
	@echo "$(WHITE)WHITE$(DEF_COLOR)"

