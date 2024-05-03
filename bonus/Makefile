CC = cc
CFLAGS = -Wall -Wextra -Werror
# -fsanitize=thread -g

SRCB = ft_atoi.c parsing.c philo_bonus.c utils.c init_data.c \
		display_msg.c getters_setters.c \
		monitoring.c string_utils.c routine.c create_processes.c

OBJB = $(SRCB:.c=.o)

BPATH = ./bouns/

TARGET_BONUS = philo

all : $(TARGET_BONUS)


bonus : $(TARGET_BONUS)

$(TARGET_BONUS) : $(OBJB)
	$(CC) $(CFLAGS) -o $@ $^


$(BPATH)%.o : $(BPATH)%.c $(BPATH)philo_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJB)

fclean : clean
	rm -f $(TARGET_BONUS)

re : fclean all