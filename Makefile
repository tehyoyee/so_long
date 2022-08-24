NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -c
RM = rm -f
AR = ar
CRS = crs
INC_DIR = includes
SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, \
		main.c \
		get_next_line.c \
		get_next_line_utils.c \
		utils.c \
		init.c \
		key_press.c \
		ft_split.c \
		check.c \
		draw_map.c \
		move.c \
		)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -I $(INC_DIR) $< -o $@

$(NAME): $(OBJS)
		$(CC) -o $@ $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re