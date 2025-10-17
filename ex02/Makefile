NAME = no_you_need_form_28b_not_28c
CC = g++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++98

SRC =	    src/main.cpp \
    src/Bureaucrat.cpp \
    src/AForm.cpp \
    src/ShrubberyCreationForm.cpp \
    src/RobotomyRequestForm.cpp \
    src/PresidentialPardonForm.cpp \


OBJS = $(notdir $(SRC:.cpp=.o))
OBJDIR = no_you_need_form_28b_not_28c_objects

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
