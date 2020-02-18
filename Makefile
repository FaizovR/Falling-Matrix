NAME = Lab_1
OBJECTS_DIR = objects
INCLUDES_DIR = includes
SOURCES_DIR = src
FLAGS = -lncurses
CC = g++
SOURCES = Exception.cpp Game.cpp Line.cpp main.cpp Point.cpp

SRCS = $(addprefix $(SOURCES_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJECTS_DIR)/,$(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -I $(INCLUDES_DIR) -lncurses

# $(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp
# 	mkdir -p $(OBJECTS_DIR)
# 	$(CC) $(FLAGS) -I $(INCLUDES_DIR)/Exception.h $(INCLUDES_DIR)/Game.h $(INCLUDES_DIR)/Lab_1.h $(INCLUDES_DIR)/Line.h $(INCLUDES_DIR)/Point.h -o $@ -c $<

clean:
	rm -rf $(OBJECTS_DIR)
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean clean

.PHONY: all clean fclean re