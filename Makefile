#################################################################################################
###**										push_swap										**###
#####***************************************************************************************#####

###-------------------------------------------------------------------------------------------###
###**							Variables and dependencies									**###
#####---------------------------------------------------------------------------------------#####
NAME = push_swap

CC = cc

CFLAGS =  -g #-fsanitize=address

INCLUDES = includes

SRCS := srcs/ALMIGHTY_PUSH_SWAP/almighty_ps.c srcs/ALMIGHTY_PUSH_SWAP/push_to_a.c	\
		srcs/ALMIGHTY_PUSH_SWAP/push_to_b1.c srcs/ALMIGHTY_PUSH_SWAP/push_to_b2.c	\
		srcs/operations/operations1.c srcs/operations/operations2.c					\
		srcs/parsing/parsing1.c srcs/parsing/parsing2.c								\
		srcs/utils/libft_utils.c srcs/utils/utils_fts1.c srcs/utils/utils_fts2.c	\
		srcs/utils/utils_fts3.c srcs/utils/utils_fts4.c								\
		srcs/ll_fts.c srcs/push_swap.c srcs/sort.c									\

OBJS :=$(SRCS:.c=.o)

###*******************************************************************************************###
###**										Bonus											**###
#####***************************************************************************************#####

BONUS_NAME = checker

SRCS_BONUS := 	bonus/checker.c bonus/utils.c bonus/get_next_line/get_next_line.c			\
				bonus/get_next_line/get_next_line_utils.c bonus/b_operations/ops1.c 		\
				bonus/b_operations/ops2.c 		\
				srcs/utils/libft_utils.c srcs/parsing/parsing1.c
				 
OBJS_BONUS :=$(SRCS_BONUS:.c=.o)

#################################################################################################

# colors
RED    = 	\033[0;31m
GREEN  = 	\033[0;32m
ORANGE = 	\033[0;33m
BLUE   = 	\033[34m
PURPLE = 	\033[35m
RESET  = 	\033[0m

###+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++###
###**								PHONY targets and rules									**###
#####+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#####

.PHONY: all bonus clean fclean norm re

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)⬤ $(BLUE)⬤ $(GREEN)⬤ $(BLUE)⬤ $(GREEN)⬤\n"
	@echo "$(ORANGE)      █████  ██      ███    ███ ██  ██████  ██   ██ ████████ ██    ██"
	@echo "$(ORANGE)     ██   ██ ██      ████  ████ ██ ██       ██   ██    ██     ██  ██ "
	@echo "$(ORANGE)     ███████ ██      ██ ████ ██ ██ ██   ███ ███████    ██      ████  "
	@echo "$(ORANGE)     ██   ██ ██      ██  ██  ██ ██ ██    ██ ██   ██    ██       ██   "
	@echo "$(ORANGE)     ██   ██ ███████ ██      ██ ██  ██████  ██   ██    ██       ██   "
	@echo "                                                                         "
	@echo "$(GREEN)██████╗ ██╗   ██╗███████╗██╗  ██╗    $(BLUE)  ██████  █     █░ ▄▄▄       ██▓███  "
	@echo "$(GREEN)██╔══██╗██║   ██║██╔════╝██║  ██║    $(BLUE)▒██    ▒ ▓█░ █ ░█░▒████▄    ▓██░  ██▒"
	@echo "$(GREEN)██████╔╝██║   ██║███████╗███████║    $(BLUE)░ ▓██▄   ▒█░ █ ░█ ▒██  ▀█▄  ▓██░ ██▓▒"
	@echo "$(GREEN)██╔═══╝ ██║   ██║╚════██║██╔══██║    $(BLUE)  ▒   ██▒░█░ █ ░█ ░██▄▄▄▄██ ▒██▄█▓▒ ▒"
	@echo "$(GREEN)██║     ╚██████╔╝███████║██║  ██║    $(BLUE)▒██████▒▒░░██▒██▓  ▓█   ▓██▒▒██▒ ░  ░"
	@echo "$(GREEN)╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    $(BLUE)▒ ▒▓▒ ▒ ░░ ▓░▒ ▒   ▒▒   ▓▒█░▒▓▒░ ░  ░"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@
	@echo -n "$(GREEN)⬤ $(BLUE)⬤ $(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $@
	@echo "\n$(GREEN) DONE!!!"

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "$(ORANGE)┌────────────────────────────────────────────────────────────────────────┐"
	@echo "│                              $(GREEN)[✓] CLEANED!$(ORANGE)                              │"
	@echo "$(ORANGE)└────────────────────────────────────────────────────────────────────────┘$(RESET)"

fclean : clean
		@rm -f $(NAME) $(BONUS_NAME)

# norm : 

re : fclean all

#####***************************************************************************************#####
###**										Good luck!										**###
#################################################################################################