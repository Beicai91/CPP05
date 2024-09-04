NAME = Intern
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98
H_PATH = -I.
ODIR = ofiles
SUCCESS = $(GREEN)✔$(RESET)
SRCS = Bureaucrat.cpp \
	   AForm.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp \
	   Intern.cpp \
	   main.cpp
OBJS = $(patsubst %.cpp,$(ODIR)/%.o,$(SRCS))

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@printf "$(SUCCESS) $(GREEN) Excutable ready$(RESET)\n"

$(OBJS):$(ODIR)/%.o:%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLASG) $(H_PATH) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(ODIR)
	@printf "$(YELLOW) Object files removed$(RESET)\n"

fclean:clean
	@rm -f $(NAME)
	@printf "$(YELLOW) Executable removed$(RESET)\n"

re:fclean all

.PHONY: all clean fclean re
