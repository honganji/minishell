NAME := minishell
EXE_CMD_NAME := minishell_exe
EXE_PIPE_NAME := minishell_pipe
EXE_TEST_NAME := minishell_test

LIB_DIR := 42-c-library
EXE_DIR := execution
UTILS_DIR := utils
PIPE_DIR := pipe
ENV_DIR := env
OBJ_DIR := objs
OBJ_DIR_COLLECTION := $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(EXE_DIR) \
					  $(UTILS_DIR) $(PIPE_DIR) $(ENV_DIR))

SOURCE := main.c \
		  $(addprefix $(ENV_DIR)/, \
		  env.c) \
		  $(addprefix $(EXE_DIR)/, \
		  execution.c builtin_fn_1.c builtin_fn_2.c) \
		  $(addprefix $(PIPE_DIR)/, \
		  pipe.c) \
		  $(addprefix $(UTILS_DIR)/, \
		  builtin_fn_1.c builtin_fn_2.c)

SOURCE_EXE := $(addprefix $(EXE_DIR)/, \
			  main.c execution.c builtin_fn_1.c builtin_fn_2.c) \
			  $(addprefix $(UTILS_DIR)/, \
			  builtin_fn_1.c builtin_fn_2.c builtin_fn_3.c) \
			  $(addprefix $(PIPE_DIR)/, \
			  pipe.c) \
			  $(addprefix $(ENV_DIR)/, \
			  env.c)

SOURCE_PIPE := $(addprefix $(EXE_DIR)/, \
			  execution.c builtin_fn_1.c builtin_fn_2.c) \
			  $(addprefix $(UTILS_DIR)/, \
			  builtin_fn_1.c builtin_fn_2.c builtin_fn_3.c) \
			  $(addprefix $(PIPE_DIR)/, \
			  pipe.c main.c) \
			  $(addprefix $(ENV_DIR)/, \
			  env.c)

SOURCE_TEST := $(addprefix $(PIPE_DIR)/, redirection.c) \
			   $(addprefix $(EXE_DIR)/, \
			   execution.c builtin_fn_1.c builtin_fn_2.c) \
			   $(addprefix $(UTILS_DIR)/, \
			   builtin_fn_1.c builtin_fn_2.c) \

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
	$(CC) $(CC_FLAG) $(SOURCE_EXE) $(LIBFT) -o $(EXE_CMD_NAME) $(LDLIBS)
	./$(EXE_CMD_NAME)

exe_pipe: $(LIBFT)
	$(CC) $(CC_FLAG) $(SOURCE_PIPE) $(LIBFT) -o $(EXE_PIPE_NAME) $(LDLIBS)
	./$(EXE_PIPE_NAME)

exe_test:
	$(CC) $(CC_FLAG) $(SOURCE_TEST) $(LIBFT) -o $(EXE_TEST_NAME) $(LDLIBS)
	./$(EXE_TEST_NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	@echo "$(BLUE)Start compiling...$(NC)"
	$(MAKE_DIR) $(OBJ_DIR_COLLECTION)

.PHONY: all clean fclean re exe clean_lib exe_execution

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m