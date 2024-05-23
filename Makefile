NAMEC			= client
NAMES			= server
NAMEC_BONUS		= client_bonus
NAMES_BONUS		= server_bonus
SRCS			= server.c helper.c
SRCC			= client.c ft_atoi.c
SRCS_BONUS		= server_bonus.c helper.c
SRCC_BONUS		= client_bonus.c ft_atoi.c
OBJS			= $(SRCS:.c=.o)
OBJC			= $(SRCC:.c=.o)
OBJBC			= $(SRCC_BONUS:.c=.o)
OBJBS			= $(SRCS_BONUS:.c=.o)
PRINTF			= libftprintf.a
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror

all:			$(NAMEC) $(NAMES)

$(NAMEC):		$(OBJC)
			@make -C ft_printf
			cc $(CFLAGS) $(OBJC) -I include ft_printf/$(PRINTF) -o $(NAMEC)
			
$(NAMES):		$(OBJS)
			@make -C ft_printf
			cc $(CFLAGS) $(OBJS) -I include ft_printf/$(PRINTF) -o $(NAMES)
			@echo "Server And Client Are Ready!"
			
bonus:			$(NAMEC_BONUS) $(NAMES_BONUS)
			@echo "BONUS Server And Client Are Ready!"
				
$(NAMEC_BONUS):		$(OBJBC)
			@make -C ft_printf
			cc $(CFLAGS) $(OBJBC) -I include ft_printf/$(PRINTF) -o $(NAMEC_BONUS)
			
$(NAMES_BONUS): 	$(OBJBS)
			@make -C ft_printf
			cc $(CFLAGS) $(OBJBS)  -I include ft_printf/$(PRINTF) -o $(NAMES_BONUS)
			
clean:
			$(RM) $(OBJS) $(OBJC) $(OBJBS) $(OBJBC)
			@make clean -s -C ft_printf
			
fclean:			clean
			$(RM) $(NAMEC)
			$(RM) $(NAMES)
			$(RM) $(NAMEC_BONUS)
			$(RM) $(NAMES_BONUS)
			@make fclean -s -C ft_printf
			@echo "Server and Client Have Been Cleaned Successfully"
			
re:			fclean all

run: 			all
			@./$(SERVER)
	
.PHONY:			all clean fclean re bonus
