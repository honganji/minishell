NAME = minishell

LIB_DIR = 42-c-library
OBJ_DIR = objs

SOURCE = main.c
HEADER = minishell.h

OBJS = $(SOURCE:%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIB_DIR)/libft.a

RM = rm
CC = cc
MAKE_DIR = mkdir
MAKE = make

RM_FLAG = -rf
CC_FLAG = -Wall -Werror -Wextra
MAKE_FLAG = -C
LDLIBS = -lreadline

all: $(LIBFT) $(NAME)

$(LIBFT):
	@if [ -z "$(shell ls -A $(LIB_DIR))" ]; then \
		git submodule init $(LIB_DIR); \
		git submodule update $(LIB_DIR); \
	fi
	@echo "\033[1;34mStart compiling libft...\033[0m"
	@$(MAKE) $(MAKE_FLAG) $(LIB_DIR)
	@echo "\033[1;32mBuild libft successfully!\033[0m"

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADER)
	@$(CC) $(CC_FLAG) $(LDLIBS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(RM) $(RM_FLAG) $(OBJ_DIR) $(LIB_DIR)/objs
	@echo "\033[1;32mCleaned object files successfully!\033[0m"

fclean: clean
	@$(RM) $(RM_FLAG) $(NAME) $(LIBFT)
	@echo "\033[1;32mCleaned executable and library successfully!\033[0m"

re: fclean all

exe: all
	./$(NAME)

clean_lib:
	@cd $(LIB_DIR) && ls -A | xargs rm -rf

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	@echo "$(BLUE)Start compiling...$(NC)"
	$(MAKE_DIR) $(OBJ_DIR)

.PHONY: all clean fclean re exe clean_lib