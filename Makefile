CFLAGS = -Wall -Wextra -Werror -MMD -MP
CC = cc
AR = ar
ARFLAG = -rcs

DEPS = helper_function.d parsing.d main.d sorting.d

-include $(DEPS)

GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
RED    = \033[31m
RESET  = \033[0m

FILE = helper_function.c parsing.c main.c sorting.c

LIB_D = libft/

LIB = $(LIB_D)libft.a

SRCDIR = src/

SRCS = $(SRCDIR)$(FILE)

INCDIR = inc/

INC = push_swap.h

OBJDIR = .Obj/

OBJS = $(FILE:%.c=$(OBJDIR)%.o)

NAME = push_swap

all: $(LIB) $(NAME) $(INCDIR)$(INC)

$(NAME) : $(OBJS) $(LIB)
	@echo "$(YELLOW)Creating final product : $(BLUE)$@...$(RESET)"
	@$(CC) $(CFLAGS) $? -o $@ && echo "$(GREEN)$@ Created successfully !$(RESET)"

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCDIR) $(LIB_D)$(INCDIR) | $(OBJDIR)
	$(CC) -c $(CFLAGS) -I $(INCDIR) -I $(LIB_D)$(INCDIR) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling...$(RESET)"

$(LIB): FORCE
	@$(MAKE) -C $(LIB_D) --no-print-directory

clean:
	@echo "$(RED)Deleting object files...$(RESET)"
	@rm -rf $(OBJDIR) && echo "$(GREEN)Done !$(RESET)"
	@$(MAKE) $@ -C $(LIB_D) --no-print-directory
	

fclean: clean
	@echo "$(RED)Deleting executable or library $(NAME)...$(RESET)"
	@rm -f $(NAME) && echo "$(GREEN)Done !$(RESET)"
	@$(MAKE) $@ -C $(LIB_D) --no-print-directory
	

re: fclean all

FORCE:

.PHONY: clean fclean re all bonus