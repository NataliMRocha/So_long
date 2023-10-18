NAME	:= so_long
CC		:= gcc
CFLAGS	:= -g3 #-Wextra -Wall -Werror
LIBMLX	:= ./MLX42
LIBFT	:= ./libft
BIN		:= ./bin/

HEADERS	:= -I ./include -I $(LIBMLX)/include -I ./libft
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm ./libft/libft.a
SRCS	:= $(addprefix ./src/, so_long.c move.c init.c close.c map.c)
OBJS	:= $(patsubst ./src/%.c,$(BIN)%.o,$(SRCS))

all: libft libmlx $(BIN) $(NAME)

libft:
	@make -sC ./libft

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

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