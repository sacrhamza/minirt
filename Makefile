CC = cc

HEADERS_DIR = include

FLAGS = -Wall -Wextra -Werror -I $(HEADERS_DIR)

TARGET = miniRt

FILES = mandatory/parsing/minirt.c mandatory/parsing/parsing.c

OBJECT_FILES = $(FILES:%.c=%.o)


all: $(TARGET)

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) $< -c -o $@

$(TARGET): $(OBJECT_FILES) libft/libft.a
	$(CC) $(FLAGS) $^ -o $(TARGET) -lm libft/libft.a

libft/libft.a:
	make -C libft

clean:
	$(RM) $(OBJECT_FILES) 
	make fclean -C libft

fclean: clean
	$(RM) $(TARGET)

re: fclean all

DATE = $(shell date +%F/%H/%M)

push:
	push "automatic push $(DATE)"

norm:
	norminette $(FILES) $(HEADER_FILE)
run: $(TARGET)
	./$(TARGET)
