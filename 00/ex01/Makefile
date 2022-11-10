NAME = phonebook
CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g -pedantic #-fsanitize=address

OBJDIR = build/
HEADER = 
SRCS := main.cpp PhoneBook.cpp Contact.cpp


OBJS := $(SRCS:.cpp=.o)
OBJECTS_PREFIXED := $(addprefix $(OBJDIR), $(OBJS))

.PHONY: test

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

test: CFLAGS+= -fsanitize=address -fsanitize=leak

test: re