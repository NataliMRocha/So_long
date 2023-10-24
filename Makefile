NAME		:= so_long
NAME_BONUS	:= so_long_bonus
CC			:= gcc
CFLAGS		:= -Wextra -Wall -Werror
LIBMLX		:= ./MLX42
LIBFT		:= ./libft
BIN			:= ./bin/
BIN_BONUS	:= ./bin/

HEADERS			:= -I ./mandatory/so_long.h -I $(LIBMLX)/include -I ./libft
LIBS			:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm ./libft/libft.a
SRCS			:= $(addprefix ./src/mandatory/, so_long.c move.c init.c close.c map.c messages.c validation.c)
OBJS			:= $(patsubst ./src/mandatory/%.c,$(BIN)%.o,$(SRCS))
SRCS_BONUS		:= $(addprefix ./src/bonus/, so_long_bonus.c move_bonus.c init_bonus.c \
						close_bonus.c map_bonus.c messages_bonus.c validation_bonus.c)
OBJS_BONUS		:= $(patsubst ./src/bonus/%.c,$(BIN)%.o,$(SRCS_BONUS))
HEADERS_BONUS	:= -I ./bonus/so_long_bonus.h -I $(LIBMLX)/include -I ./libft

ifdef WITH_BONUS
	SRCS = $(SRCS_BONUS)
	OBJS = $(OBJS_BONUS)
	HEADERS = $(HEADERS_BONUS)
	BIN = $(BIN_BONUS)
	NAME = $(NAME_BONUS)
endif

all: libft libmlx $(BIN) $(NAME)

LIBFT_CHECK = $(shell ar -t ./libft/libft.a)
LIBMLX_CHECK = $(shell ar -t $(LIBMLX)/build/libmlx42.a)

ifeq ($(LIBFT_CHECK), )
libft:
	@make -sC ./libft
endif

ifeq ($(LIBMLX_CHECK), )
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
endif

$(BIN)%.o: ./src/mandatory/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(BIN_BONUS)%.o: ./src/bonus/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS_BONUS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BIN):
	@mkdir -p $(BIN)

bonus:
	@$(MAKE) WITH_BONUS=TRUE --no-print-directory

clean:
	rm -rf $(BIN)
	rm -rf $(LIBMLX)/build
	@make clean -sC ./libft 

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	rm -rf ./libft/libft.a

re: clean all

.PHONY: all clean fclean re libmlx libft