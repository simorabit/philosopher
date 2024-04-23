#include "philo.h"

void set_long(pthread_mutex_t *mutex, long *dest, long value)
{
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);
}
long get_long(pthread_mutex_t *mutex, long *value)
{
    long var;

    pthread_mutex_lock(mutex);
    var = *value;
    pthread_mutex_unlock(mutex);
    return var;
}

int get_bool(pthread_mutex_t *mutex, int *value)
{
    int var;

    pthread_mutex_lock(mutex);
    var = *value;
    pthread_mutex_unlock(mutex);
    return var;
}
void set_bool(pthread_mutex_t *mutex, int *dest, int value)
{
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);
}