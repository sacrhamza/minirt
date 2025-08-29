CC = cc

HEADER_DIR = include

FLAGS = -Wall -Wextra -Werror -I $(HEADER_DIR)

TARGET = miniRt

FILES = mandatory/parsing/minirt.c mandatory/parsing/parsing.c

OBJECT_FILES = $(FILES:%.c=%.o)


all: $(TARGET)

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) $< -c -o $@

$(TARGET): $(OBJECT_FILES)
	$(CC) $(FLAGS) $^ -o $(TARGET) -lm

clean:
	$(RM) $(OBJECT_FILES) 

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
