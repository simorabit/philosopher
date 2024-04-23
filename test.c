#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h> // for O_CREAT, O_EXCL constants
#include <unistd.h> // for sleep function

int main() {
    sem_t *sem; // Semaphore pointer

    // Create or open a named semaphore
    sem = sem_open("/my_semaphore", O_CREAT | O_EXCL, 0644, 1); // Initial value of 1

    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore created or opened.\n");

    // Now you can perform operations on the semaphore, like wait and post

    // Wait on the semaphore
    printf("Waiting on semaphore...\n");
    if (sem_wait(sem) == -1) {
        perror("sem_wait");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore acquired.\n");

    // Simulate some work
    sleep(2);

    // Post (release) the semaphore
    if (sem_post(sem) == -1) {
        perror("sem_post");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore released.\n");

    // Close the semaphore
    if (sem_close(sem) == -1) {
        perror("sem_close");
        exit(EXIT_FAILURE);
    }

    // Unlink the semaphore (remove it from the system)
    if (sem_unlink("/my_semaphore") == -1) {
        perror("sem_unlink");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore closed and unlinked.\n");

    return 0;
}
