CC = gcc
CFLAGS = -Wall -Wextra -Werror 
# -fsanitize=thread -g
SRCS = ft_atoi.c parsing.c philo.c utils.c init_data.c philo_state.c getter_setters.c monitoring.c

OBJS = $(SRCS:.c=.o)

TARGET = philo

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all