#!/bin/bash

# Fungsi untuk menjalankan tugas
task() {
    local id=$1
    local duration=$2
    echo "Task $id started, will take $duration seconds."
    sleep $duration
    echo "Task $id completed."
}

# Menjalankan tugas secara paralel dan menyimpan PID dari setiap tugas
task 1 3 &
pid1=$!
task 2 5 &
pid2=$!
task 3 2 &
pid3=$!

# Menunggu semua tugas selesai (simulasi join thread)
wait $pid1
wait $pid2
wait $pid3

echo "All tasks completed."
