CC = cc
CFLAGS = -Wall -Wextra -Werror
# -fsanitize=thread -g

mnd = mandatory/
bns = bouns/

SRCS = $(mnd)ft_atoi.c $(mnd)parsing.c $(mnd)philo.c $(mnd)utils.c $(mnd)init_data.c \
		$(mnd)philo_state.c $(mnd)getter_setters.c $(mnd)monitoring.c

SRCB = bonus/ft_atoi.c bonus/parsing.c bonus/philo_bonus.c bonus/utils.c bonus/init_data.c \
		bonus/philo_state.c bonus/getters_setters.c bonus/monitoring.c

OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)

MPATH = ./mandatory/
BPATH = ./bouns/

TARGET = philo
TARGET_BONUS = philo_bonus

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(MPATH)%.o : $(MPATH)%.c $(MPATH)philo.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(TARGET_BONUS)

$(TARGET_BONUS) : $(OBJB)
	$(CC) $(CFLAGS) -o $@ $^


$(BPATH)%.o : $(BPATH)%.c $(BPATH)philo_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET) $(TARGET_BONUS)

re : fclean all