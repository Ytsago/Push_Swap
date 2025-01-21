CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar
ARFLAG = -rcs

GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
RED    = \033[31m
RESET  = \033[0m

FILE =	main.c sort_three.c pivo_sort.c lst_stack.c incertion.c median.c

IFILE = helper_function.c parsing.c ft_putstack.c ft_rotate.c \
		ft_rev_rotate.c ft_swap.c lst_stack.c

BFILE = checker.c

LIB_D = libft/

LIB = $(LIB_D)libft.a

SRCDIR = src/

SRCS = $(SRCDIR)$(FILE) $(SRCDIR)$(IFILE)

INCDIR = inc/

INC = push_swap.h

OBJDIR = .Obj/

OBJS = $(FILE:%.c=$(OBJDIR)%.o) $(IFILE:%.c=$(OBJDIR)%.o)

NAME = push_swap
BNAME = checker

all: $(NAME)

$(NAME) : $(OBJS)
	@echo "$(YELLOW)Creating final product : $(BLUE)$@...$(RESET)"
	@$(CC) $(CFLAGS) $^ $(LIB) -o $@ && echo "$(GREEN)$@ Created successfully !$(RESET)"

$(OBJDIR)%.o: $(SRCDIR)%.c $(LIB) $(INCDIR)$(INC) | $(OBJDIR)
	$(CC) -c $(CFLAGS) -I $(INCDIR) -I $(LIB_D)$(INCDIR) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling...$(RESET)"

$(LIB): FORCE
	@$(MAKE) -C $(LIB_D) --no-print-directory

bonus: all
	@$(MAKE) NAME="$(BNAME)" FILE="$(BFILE)" MAKEOVERRIDES=

clean:
	@echo "$(RED)Deleting object files...$(RESET)"
	@rm -rf $(OBJDIR) && echo "$(GREEN)Done !$(RESET)"
	@$(MAKE) $@ -C $(LIB_D) --no-print-directory
	

fclean: clean
	@echo "$(RED)Deleting executable or library $(NAME)...$(RESET)"
	@rm -f $(NAME) && echo "$(GREEN)Done !$(RESET)"
	@if [ -f "$(BNAME)" ]; then \
	echo "$(RED)Deleting executable or library $(BNAME)...$(RESET)"; \
	rm -f $(BNAME) && echo "$(GREEN)Done !$(RESET)"; \
	fi
	@$(MAKE) $@ -C $(LIB_D) --no-print-directory
	
re: fclean all

FORCE:

.PHONY: clean fclean re all bonus