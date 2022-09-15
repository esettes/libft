GREEN	= \033[0;32m
WHITE	= \033[0;37m
BWHITE	= \033[1;37m
LGREEN	= \033[2;32m
LWHITE	= \033[2;37m
RESET	= \033[2;33m

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRCS	= $(addprefix $(SRCDIR), $(SRCNAMES))

OBJDIR	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

B_SRCDIR	= ./bonus/
B_SRCNAMES	= $(shell ls $(B_SRCDIR) | grep -E ".+\.c")
B_SRCS	= $(addprefix $(B_SRCDIR), $(B_SRCNAMES))
OBJB	= $(addprefix $(OBJDIR), $(B_SRCNAMES:.c=.o))

NAME	= libft.a
BONUS	= .
CC  = gcc
RM  = rm -f
CFLAGS  = -Wall -Wextra -Werror
AR = ar rc

HEADER	= -I include -I ./inc/

$(OBJDIR)%.o:$(SRCDIR)%.c
#	@echo "${LWHITE}Compiling $(notdir $<) ${LGREEN}✓$(RESET)"
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

#Change libx42_flags position at the end of the coommand
$(NAME):	$(OBJS)
	@${AR} ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(RESET)\033[2;33m"
	@echo "${BWHITE}Compilation ${GREEN}[OK]$(RESET)\033[2;33m" 

$(OBJDIR)%.o:$(B_SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

${BONUS}:	${OBJS} ${OBJB}
		@${AR}	${NAME} ${OBJB}
		@ranlib ${NAME}

bonus:	${BONUS}

all:	${NAME}

clean:
		@${RM} ${OBJS} ${OBJB}

fclean:	clean
		@${RM} ${NAME}
		@echo "${BWHITE}Clean all ${GREEN}[OK]\033[2;33m"

re:		fclean all bonus

.PHONY:	all clean fclean re
