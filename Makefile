NAME	 := so_long
CFLAGS	 := -Wextra -Wall -Werror -Wunreachable-code -Ofast -fsanitize=address -g
LIBMLX	 := ./MLX42
LIBMLX_A := ./MLX42/build/libmlx42.a
LIBFT	 := ./libft
LIBFT_A	 := ./libft/libft.a

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS	:= $(LIBMLX_A) $(LIBFT_A) -ldl -lglfw -pthread -lm -fsanitize=address -g
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: $(LIBFT_A) $(LIBMLX_A) $(NAME)

$(LIBFT_A):
	make -C $(LIBFT) re

$(LIBMLX_A):
	git clone https://github.com/codam-coding-college/MLX42 --depth=1
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# && printf "Compiling: $(notdir $<)\n"
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT_A)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx