CC = cc
CFLAGS = -Wall -Wextra -Werror 
# -g -fsanitize=thread 

SRCS = ft_atoi.c parsing.c philo.c utils.c init_data.c \
		philo_state.c getter_setters.c monitoring.c

OBJS = $(SRCS:.c=.o)

MPATH = ./mandatory/

TARGET = philo

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(MPATH)%.o : $(MPATH)%.c $(MPATH)philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) 

fclean : clean
	rm -f $(TARGET)

re : fclean all