#!/bin/bash

# Path ke file lock
LOCK_FILE="/tmp/my_mutex.lock"

# Fungsi untuk mengambil lock
acquire_lock() {
    # Mencoba membuat file lock
    while ! ln -s $$ "$LOCK_FILE" 2>/dev/null; do
        sleep 0.1
    done
}

# Fungsi untuk melepaskan lock
release_lock() {
    rm -f "$LOCK_FILE"
}

# Fungsi untuk tugas yang membutuhkan mutex
critical_section() {
    echo "Critical section entered by process $$"
    sleep 3  # Simulasi kerja di critical section
    echo "Critical section completed by process $$"
}

# Mengambil lock sebelum masuk ke critical section
acquire_lock

# Memasuki critical section
critical_section

# Melepaskan lock setelah selesai dengan critical section
release_lock
