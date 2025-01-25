# $@: name of the target file (one before colon)
# $<: name of first prerequisite file (first one after colon)
# $^: names of all prerequisite files (space separated)
# $*: stem (bit which matches the % wildcard in rule definition)
#
# VAR = val: Normal setting - values within are recursively expand when var used.
# VAR := val: Setting of var with simple expansion of values inside - values are expanded at decl time.
# VAR ?= val: Set var only if it doesn't have a value.
# VAR += val: Append val to existing value (or set if var didn't exist).

# Program name and output directory
NAME = libft.a
OUTPUT_DIR = .

# Other directories
INCLUDES_DIR = 		incl
SOURCES_ROOT_DIR =	srcs
SOURCES_DIR :=		$(wildcard $(SOURCES_ROOT_DIR)/*)
OBJECTS_ROOT_DIR =	objs
OBJECTS_DIR :=		$(patsubst $(SOURCES_ROOT_DIR)/%,$(OBJECTS_ROOT_DIR)/%,$(SOURCES_DIR))

# Files
HEADERS =	$(INCLUDES_DIR)/libft.h
SOURCES = 	$(wildcard $(SOURCES_ROOT_DIR)/*/*.c)
OBJECTS :=	$(patsubst $(SOURCES_ROOT_DIR)/%.c,$(OBJECTS_ROOT_DIR)/%.o,$(SOURCES))

# Compiler and options
CC = cc
CFLAGS += -Wall -Wextra -Werror
DEST = $(OUTPUT_DIR)

# Phony targets
.PHONY: all clean fclean re aclean test

# Targets
all: $(NAME)
$(NAME): $(OBJECTS)
	@echo "----------------"
	@echo "make $(NAME) OBJECTS done.\n"
	ar rcs $@ $(OBJECTS)
	@echo "----------------"
	@echo "make $(NAME) done.\n"

# Compile Targets
$(OBJECTS_ROOT_DIR)/%.o: $(SOURCES_ROOT_DIR)/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@
$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_ROOT_DIR)
	mkdir -p $(OBJECTS_DIR)

clean:
	rm -rf $(OBJECTS_ROOT_DIR)
fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
re: fclean all

# non mandatory
aclean: all clean
ar:
	ar rcs $(OUTPUT_DIR)/$(NAME) $(OBJECTS)
test:
	@echo "NAME:             $(NAME)"
	@echo "OUTPUT_DIR:       $(OUTPUT_DIR)"
	@echo "HEADERS:          $(HEADERS)"
	@echo "SOURCES_ROOT_DIR: $(SOURCES_ROOT_DIR)"
	@echo "SOURCES_DIR:      $(SOURCES_DIR)"
	@echo "OBJECTS_ROOT_DIR: $(OBJECTS_ROOT_DIR)"
	@echo "OBJECTS_DIR:      $(OBJECTS_DIR)"
	@echo "----------------"
	@echo "SOURCES:\n$(SOURCES)\n"
	@echo "OBJECTS:\n$(OBJECTS)"
	@echo "----------------"
	@echo "CC: $(CC)"
	@echo "CFLAGS: $(CFLAGS)"
	@echo "DEST: $(DEST)"
