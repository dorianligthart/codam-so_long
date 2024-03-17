ROOT_NAMES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_printf.c ft_free.c ft_mapchr.c ft_len.c
LST_NAMES = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
GNL_NAMES = get_next_line.c get_next_line_bonus.c
SRC_NAMES = $(ROOT_NAMES) $(GNL_NAMES) $(LST_NAMES)

ROOT_SRC   = $(addprefix src/, $(ROOT_NAMES))
LST_SRC   = $(addprefix src/lst/, $(LST_NAMES))
GNL_SRC   = $(addprefix src/gnl/, $(GNL_NAMES))
SRC       = $(ROOT_SRC) $(LST_SRC) $(GNL_SRC)
OBJ       = $(SRC_NAMES:%.c=%.o)

NAME      = libft.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror -c -g -fsanitize=address
AR        = ar -r -c
INCLUDE   = -Iinclude
BUILD     = build/

$(NAME): fclean
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC)
	mv -f $(OBJ) $(BUILD)
	$(AR) $(NAME) $(addprefix $(BUILD), $(OBJ))
all: $(NAME)
clean:
	rm -f $(OBJ)
	rm -f $(addprefix $(BUILD), $(OBJ))
	rm -df $(BUILD)
fclean: clean
	rm -f $(NAME) $(addprefix $(BUILD), $(NAME))
re: fclean all

.PHONY: all clean fclean re
