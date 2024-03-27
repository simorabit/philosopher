CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c parsing.c philo.c 

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
	rm -f TARGET

re :
	fclean all