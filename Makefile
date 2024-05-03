NAME := minishell
EXE_NAME := minishell_exe

LIB_DIR := 42-c-library
EXE_DIR := execution
OBJ_DIR := objs

SOURCE := main.c
SOURCE_EXE := $(addprefix $(EXE_DIR)/, \
			  main.c execution.c pipe.c builtin_fn_1.c builtin_fn_2.c env.c)
HEARDER := minishell.h

OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

LIBFT := $(LIB_DIR)/libft.a

RM := rm
CC := cc
MAKE_DIR := mkdir
MAKE := make

RM_FLAG := -rf
CC_FLAG := -Wall -Werror -Wextra
MAKE_FLAG := -C
LDLIBS := -lreadline

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
	@$(CC) $(CC_FLAG) $(LDLIBS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(RM) $(RM_FLAG) $(OBJ_DIR) $(LIB_DIR)/objs
	@echo "$(GREEN)Cleaned object files successfully!$(NC)"

fclean: clean
	@$(RM) $(RM_FLAG) $(NAME) $(LIBFT)
	@echo "$(GREEN)Cleaned executable and library successfully!$(NC)"

re: fclean all

exe: all
	./$(NAME)

clean_lib:
	@cd $(LIB_DIR) && ls -A | xargs rm -rf

exe_execution: $(LIBFT)
	$(CC) $(CC_FLAG) $(SOURCE_EXE) $(LIBFT) -o $(EXE_NAME) $(LDLIBS)
	./$(EXE_NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	@echo "$(BLUE)Start compiling...$(NC)"
	$(MAKE_DIR) $(OBJ_DIR)

.PHONY: all clean fclean re exe clean_lib exe_execution

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m