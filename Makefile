NAME	:= so_long
CC		:= gcc
CFLAGS	:= -g3 -Wextra -Wall -Werror
LIBMLX	:= ./MLX42
LIBFT	:= ./libft
BIN		:= ./bin/

HEADERS	:= -I ./include -I $(LIBMLX)/include -I ./libft
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm ./libft/libft.a
SRCS	:= $(addprefix ./src/, so_long.c move.c init.c close.c map.c messages.c validation.c)
OBJS	:= $(patsubst ./src/%.c,$(BIN)%.o,$(SRCS))

all: libft libmlx $(BIN) $(NAME)

LIBFT_CHECK = $(shell ar -t ./libft/libft.a)
LIBMLX_CHECK = $(shell ar -t $(LIBMLX)/build/libmlx42.a)

ifeq ($(LIBFT_CHECK),)
libft:
	@make -sC ./libft
endif

ifeq ($(LIBMLX_CHECK),)
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
endif

$(BIN)%.o: ./src/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BIN):
	@mkdir -p $(BIN)

clean:
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build
	@make clean -sC ./libft 

fclean: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a

re: clean all

.PHONY: all clean fclean re libmlx libft