NAME = Lab_1
OBJECTS_DIR = objects
INCLUDES_DIR = includes
SOURCES_DIR = src
FLAGS = -lncurses
CC = g++
SOURCES = Exception.cpp Game.cpp Line.cpp main.cpp Point.cpp GameEngine.cpp UserInputUtilities.cpp

SRCS = $(addprefix $(SOURCES_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJECTS_DIR)/,$(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -I $(INCLUDES_DIR) -lncurses

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(FLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJECTS_DIR)
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean clean

.PHONY: all clean fclean re