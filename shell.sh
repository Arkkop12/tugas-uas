#!/bin/bash

# Variabel untuk mengontrol perulangan
should_run=true

# Fungsi untuk mengeksekusi perintah
execute_command() {
    $@
}

# Perulangan while untuk menjaga shell tetap berjalan
while $should_run; do
    # Menampilkan prompt
    echo -n "osh> "
    
    # Membaca input dari pengguna
    read input

    # Menggunakan if-else untuk memeriksa perintah 'exit'
    if [[ "$input" == "exit" ]]; then
        should_run=false
    elif [[ -n "$input" ]]; then
        # Menjalankan perintah menggunakan fungsi
        execute_command $input
    fi
done

# Menampilkan pesan keluar
echo "Shell exited."
