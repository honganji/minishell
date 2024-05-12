NAME := minishell

LIB_DIR := 42-c-library
OBJ_DIR := objs

SOURCE := main.c \
			init.c \
			tokenization.c \
			utils/utils.c \
			utils/utils_split.c \
			utils/utils_split1.c \
			parsing/grouping.c

HEADER := include/minishell.h

OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

LIBFT := $(LIB_DIR)/libft.a

RM := rm
CC := cc
MAKE_DIR := mkdir
MAKE := make

RM_FLAG := -rf
CC_FLAG := -Wall -Werror -Wextra
L_READ_LIB := -lreadline
MAKE_FLAG := -C

all: $(LIBFT) $(NAME)

$(LIBFT):
	@if [ -z "$(shell ls -A $(LIB_DIR))" ]; then \
		git submodule init $(LIB_DIR); \
		git submodule update $(LIB_DIR); \
	fi
	@echo "$(BLUE)Start compiling libft...$(NC)"
	@$(MAKE) $(MAKE_FLAG) $(LIB_DIR)
	@echo "$(GREEN)Build libft successfully!$(NC)"

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADER)
	@$(CC) $(CC_FLAG) $(OBJS) $(LIBFT) $(L_READ_LIB) -o $(NAME)

clean:
	@$(RM) $(RM_FLAG) $(OBJ_DIR) $(LIB_DIR)/objs
	@echo "$(GREEN)Clean object files successfully$(NC)"

fclean: clean
	@$(RM) $(RM_FLAG) $(NAME) $(LIBFT)
	@echo "$(GREEN)Clean executable and library successfully!$(NC)"

re: fclean all

exe: all
	./$(NAME)

clean_lib:
	@cd $(LIB_DIR) && ls -A | xargs rm -rf

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	@echo "$(BLUE)Start compiling...$(NC)"
	$(MAKE_DIR) $(OBJ_DIR) $(OBJ_DIR)/utils $(OBJ_DIR)/parsing

.PHONY: all clean fclean re exe clean_lib

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m