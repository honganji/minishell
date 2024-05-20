NAME := minishell

LIB_DIR := 42-c-library
EXE_DIR := execution
UTILS_DIR := utils
PIPE_DIR := pipe
ENV_DIR := env
TEST_DIR := test
INIT_DIR := init
ERRORS_DIR := errors
PARSING_DIR := parsing
SIGNAL_DIR := set_signal
OBJ_DIR := objs
OBJ_DIR_COLLECTION := $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(EXE_DIR) \
					  $(UTILS_DIR) $(PIPE_DIR) $(ENV_DIR) $(TEST_DIR) \
					  $(INIT_DIR) $(PARSING_DIR) $(ERRORS_DIR) $(SIGNAL_DIR))

SOURCE := main.c \
		  $(addprefix $(ENV_DIR)/, \
		  env.c) \
		  $(addprefix $(EXE_DIR)/, \
		  execution.c builtin_fn_1.c builtin_fn_2.c) \
		  $(addprefix $(PIPE_DIR)/, \
		  pipe.c redirection.c) \
		  $(addprefix $(UTILS_DIR)/, \
		  builtin_fn_1.c builtin_fn_2.c builtin_fn_3.c utils.c utils_split.c \
		  utils_split1.c)\
		  $(addprefix $(TEST_DIR)/, \
		  set_val.c) \
		  $(addprefix $(INIT_DIR)/, \
		  init.c) \
		  $(addprefix $(PARSING_DIR)/, \
		  grouping.c process.c redirections.c tokenization.c) \
		  $(addprefix $(ERRORS_DIR)/, \
		  critical_err.c syntax_err.c) \
		  $(addprefix $(SIGNAL_DIR)/, \
		  set_sig.c)

# SOURCE := main.c \
# 		  $(addprefix $(ENV_DIR)/, \
# 		  env.c) \
# 		  $(addprefix $(UTILS_DIR)/, \
# 		  builtin_fn_1.c builtin_fn_2.c builtin_fn_3.c utils.c utils_split.c \
# 		  utils_split1.c) \
# 		  $(addprefix $(TEST_DIR)/, \
# 		  set_val.c) \
# 		  $(addprefix $(EXE_DIR)/, \
# 		  execution.c builtin_fn_1.c builtin_fn_2.c) \
# 		  $(addprefix $(PIPE_DIR)/, \
# 		  pipe.c redirection.c)

OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

HEADER := include/minishell.h

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
	@echo "$(GREEN)Cleaned object files successfully!$(NC)"

fclean: clean
	@$(RM) $(RM_FLAG) $(NAME) $(LIBFT)
	@echo "$(GREEN)Cleaned executable and library successfully!$(NC)"

re: fclean all

exe: all
	./$(NAME)

clean_lib:
	@cd $(LIB_DIR) && ls -A | xargs rm -rf

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	@echo "$(BLUE)Start compiling...$(NC)"
	$(MAKE_DIR) $(OBJ_DIR_COLLECTION)

.PHONY: all clean fclean re exe clean_lib exe_execution

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m