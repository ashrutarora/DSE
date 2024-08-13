#include <stdio.h>                // Include the standard input/output library.
#include <pthread.h>              // Include the pthread library for multi-threading.
#include <semaphore.h>            // Include the semaphore library for synchronization.
#include <unistd.h>               // Include the unistd library for usleep function.

#define BUFFER_SIZE 5             // Define the size of the buffer.
#define MAX_ITEMS 20              // Define the maximum number of items to produce/consume.

sem_t empty, full, mutex;          // Declare three semaphores for synchronization.
int buffer[BUFFER_SIZE];          // Create a buffer to store items.
int in = 0, out = 0;              // Initialize indices for buffer.
int items_produced = 0;           // Counter for items produced.
int items_consumed = 0;           // Counter for items consumed.

// Producer thread function
void *producer(void *arg)
{
    int item = 1;                 // Initialize the item to produce.

    while (items_produced < MAX_ITEMS)
    {
        sem_wait(&empty);          // Wait if there are no empty slots in the buffer.
        sem_wait(&mutex);          // Acquire the mutex to protect the critical section.

        // Produce item and add it to the buffer.
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;  // Circular buffer, wrap around if needed.
        item++;
        items_produced++;          // Increment the item produced count.

        sem_post(&mutex);          // Release the mutex.
        sem_post(&full);           // Signal that a slot is filled.

        usleep(100000);            // Sleep for some time to simulate work.
    }
}

// Consumer thread function
void *consumer(void *arg)
{
    while (items_consumed < MAX_ITEMS)
    {
        sem_wait(&full);           // Wait if there are no items to consume.
        sem_wait(&mutex);          // Acquire the mutex to protect the critical section.

        // Consume an item from the buffer.
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;  // Circular buffer, wrap around if needed.
        items_consumed++;          // Increment the item consumed count.

        sem_post(&mutex);          // Release the mutex.
        sem_post(&empty);          // Signal that a slot is emptied.

        usleep(150000);            // Sleep for some time to simulate work.
    }
}

int main()
{
    pthread_t producer_thread, consumer_thread;  // Declare producer and consumer threads.

    sem_init(&empty, 0, BUFFER_SIZE);  // Initialize the empty semaphore with the buffer size.
    sem_init(&full, 0, 0);           // Initialize the full semaphore with zero filled slots.
    sem_init(&mutex, 0, 1);          // Initialize the mutex semaphore to 1 for mutual exclusion.

    pthread_create(&producer_thread, NULL, producer, NULL);  // Create the producer thread.
    pthread_create(&consumer_thread, NULL, consumer, NULL);  // Create the consumer thread.

    pthread_join(producer_thread, NULL);  // Wait for the producer thread to finish.
    pthread_join(consumer_thread, NULL);  // Wait for the consumer thread to finish.

    return 0;  // Exit the program.
}
