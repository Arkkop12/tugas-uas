#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Fungsi yang akan dijalankan oleh setiap thread
void* task(void* arg) {
    int id = *((int*)arg);
    printf("Thread %d: mulai\n", id);
    
    // Simulasi pekerjaan dengan sleep
    int sleep_time = rand() % 5 + 1;
    sleep(sleep_time);
    
    printf("Thread %d: selesai setelah %d detik\n", id, sleep_time);
    return NULL;
}

int main() {
    const int num_threads = 5;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];
    int i;

    // Inisialisasi random number generator
    srand(time(NULL));

    // Membuat beberapa thread
    for (i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, task, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Menunggu semua thread selesai
    for (i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
    }

    printf("Semua thread telah selesai.\n");
    return 0;
}
