NAME = span
CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

OBJDIR = build/
HEADER = 
SRCS := main.cpp Span.cpp

OBJS := $(SRCS:.cpp=.o)
OBJECTS_PREFIXED := $(addprefix $(OBJDIR), $(OBJS))


.PHONY: test all clean fclean re

$(NAME): $(OBJECTS_PREFIXED) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJECTS_PREFIXED) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_PREFIXED): build/%.o : %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: CFLAGS += -Wshadow -pedantic -g3 -fsanitize=address

test: re