#include "philo_bonus.h"

void set_long(sem_t *sem, long *dest, long value)
{
    sem_wait(sem);
    *dest = value;
    sem_post(sem);
}
long get_long(sem_t *sem, long *value)
{
    long var;
    sem_wait(sem);
    var = *value;
    sem_post(sem);
    return var;
}

int get_bool(sem_t *sem, int *value)
{
    int var;

    sem_wait(sem);
    var = *value;
    sem_post(sem);
    return var;
}
void set_bool(sem_t *sem, int *dest, int value)
{
    sem_wait(sem);
    *dest = value;
    sem_post(sem);
}