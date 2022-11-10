NAME = array
CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g #-fsanitize=address

OBJDIR = build/
HEADER = 
SRCS := main.cpp

OBJS := $(SRCS:.cpp=.o)
OBJECTS_PREFIXED := $(addprefix $(OBJDIR), $(OBJS))

UNAME_S := $(shell uname -s)

.PHONY: test sanitize

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

ifeq ($(UNAME_S),Linux)
sanitize: CFLAGS += -Wshadow -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null
endif
ifeq ($(UNAME_S),Darwin)
sanitize: CFLAGS += -Wshadow -pedantic -g3 -fsanitize=address
endif

sanitize: re