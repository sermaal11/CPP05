NAME = mommy_when_i_grow_up_i_want_to_be_a_bureaucrat
CC = g++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++98

SRC =	    src/main.cpp \
    src/Bureaucrat.cpp \


OBJS = $(notdir $(SRC:.cpp=.o))
OBJDIR = mommy_when_i_grow_up_i_want_to_be_a_bureaucrat_objects

all: $(OBJDIR) $(NAME)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	$(CC) $(CFLAGS) -o $@ $(addprefix $(OBJDIR)/, $(OBJS))

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
