READLINE_INCLUDE = $(shell brew --prefix readline)/include
READLINE_LIB = $(shell brew --prefix readline)/lib

CC = cc -g -fsanitize=address
# CFLAGS = #-Wall -Wextra -Werror 
CFLAGS = -g -fsanitize=address -I$(READLINE_INCLUDE)  # Add Readline include path
LDFLAGS = -L$(READLINE_LIB) -lreadline 
SRC_DIR = .
OBJ_DIR = obj

SRC_FILES = ft_strnjoin.c main.c \


OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

PARS_FILES = $(wildcard parsing/*.c)
PARS_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(PARS_FILES:.c=.o)))

LIBFT_FILES = $(wildcard libft/*.c)
LIBFT_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(LIBFT_FILES:.c=.o)))

BUILT_FILES = $(wildcard builtins/*.c)
BUILT_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(BUILT_FILES:.c=.o)))

EXECU_FILES = $(wildcard execution/*.c)
EXECU_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(EXECU_FILES:.c=.o)))
 
EXECUTABLE = minishell
TXT_FILES = a.out

.PHONY: all clean fclean re

all: $(EXECUTABLE)
# all:
# 	echo $(OBJ_FILES)

$(EXECUTABLE): $(LIBFT_OBJ_FILES) $(BUILT_OBJ_FILES) $(OBJ_FILES) $(PARS_OBJ_FILES) $(EXECU_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: libft/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: builtins/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: parsing/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: execution/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXECUTABLE) $(TXT_FILES)

re: fclean all
