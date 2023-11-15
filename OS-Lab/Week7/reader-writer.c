#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, wrt;                // Declare two semaphores: mutex and wrt.
int data = 0, readers = 0;       // Initialize shared data and the number of active readers.

void *reader(void *arg) {
    do {
        sem_wait(&mutex);       // Reader wants to enter the critical section, acquire the mutex.
        readers++;              // Increment the count of active readers.

        if (readers == 1)       // If this is the first reader, block writers.
            sem_wait(&wrt);     // Acquire the writer semaphore, preventing writers from writing.

        sem_post(&mutex);       // Release the mutex to allow other readers to enter.

        // Read data
        printf("Reader %d read: %d\n", *((int*)arg), data);  // Read and print the shared data.

        sem_wait(&mutex);       // Reader is done, acquire the mutex.
        readers--;              // Decrement the count of active readers.

        if (readers == 0)       // If there are no more readers, signal writers to write.
            sem_post(&wrt);     // Release the writer semaphore.

        sem_post(&mutex);       // Release the mutex to allow other readers to enter.

    } while (1);                // Continue in an infinite loop.
}

void *writer(void *arg) {
    do {
        sem_wait(&wrt);         // Writer wants to write, acquire the writer semaphore.
        data++;                 // Increment and update the shared data.
        printf("Writer %d wrote: %d\n", *((int*)arg), data);  // Write and print the shared data.
        sem_post(&wrt);         // Release the writer semaphore.

    } while (1);                // Continue in an infinite loop.
}

int main() {
    int num_readers = 3;        // Number of reader threads.
    int num_writers = 2;        // Number of writer threads.

    pthread_t readers_threads[num_readers];   // Declare an array of reader thread IDs.
    pthread_t writers_threads[num_writers];   // Declare an array of writer thread IDs.

    sem_init(&mutex, 0, 1);     // Initialize the mutex semaphore with an initial value of 1 (unlocked).
    sem_init(&wrt, 0, 1);       // Initialize the writer semaphore with an initial value of 1 (unlocked).

    int reader_args[num_readers];  // Array to store arguments for reader threads.
    int writer_args[num_writers];  // Array to store arguments for writer threads.

    for (int i = 0; i < num_readers; i++) {
        reader_args[i] = i;          // Initialize reader arguments with unique IDs.
        pthread_create(&readers_threads[i], NULL, reader, &reader_args[i]);  // Create reader threads.
    }

    for (int i = 0; i < num_writers; i++) {
        writer_args[i] = i;          // Initialize writer arguments with unique IDs.
        pthread_create(&writers_threads[i], NULL, writer, &writer_args[i]);  // Create writer threads.
    }

    for (int i = 0; i < num_readers; i++) {
        pthread_join(readers_threads[i], NULL);  // Wait for reader threads to finish.
    }

    for (int i = 0; i < num_writers; i++) {
        pthread_join(writers_threads[i], NULL);  // Wait for writer threads to finish.
    }

    sem_destroy(&mutex);    // Destroy the mutex semaphore.
    sem_destroy(&wrt);      // Destroy the writer semaphore.

    return 0;  // Exit the program.
}
