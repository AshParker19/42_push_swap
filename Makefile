NAME = push_swap

CC = cc

CFLAGS =  -g

SRC := $(wildcard *.c)

OBJ :=$(SRC:.c=.o)

# colors
RED    = 	\033[0;31m
GREEN  = 	\033[0;32m
ORANGE = 	\033[0;33m
BLUE   = 	\033[34m
PURPLE = 	\033[35m
DEF    = 	\033[0m

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@rm -rf $(OBJ) # !!! remove this shit !!!

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "$(GREEN)⬤ $(BLUE)⬤ $(ORANGE)⬤ $(DEF)"

clean:
		@rm -f $(OBJ)
		@echo "$(ORANGE)┌───────────────────────────────────────────────────┐"
		@echo "│                    $(GREEN)[✓] CLEANED$(ORANGE)                    │"
		@echo "$(ORANGE)└───────────────────────────────────────────────────┘$(DEF)"

fclean : clean
		@rm -f $(NAME)

re : fclean all
