#!/bin/bash

# Variabel untuk menyimpan jumlah total dan jumlah angka
total=0
count=0

# Meminta pengguna untuk memasukkan jumlah angka yang ingin diproses
echo "Berapa banyak angka yang ingin Anda masukkan?"
read n

# Menggunakan perulangan for untuk membaca angka dari pengguna
for ((i = 1; i <= n; i++))
do
    echo "Masukkan angka ke-$i:"
    read num
    
    # Memeriksa apakah input adalah angka
    if [[ $num =~ ^-?[0-9]+$ ]]; then
        # Menambah angka ke total dan meningkatkan jumlah angka
        total=$((total + num))
        count=$((count + 1))
    else
        echo "Input bukan angka. Silakan masukkan angka."
        i=$((i - 1))  # Mengurangi counter untuk mengulangi input
    fi
done

# Menghitung rata-rata
if [ $count -ne 0 ]; then
    average=$(echo "$total / $count" | bc -l)
    echo "Jumlah total dari angka-angka adalah: $total"
    echo "Rata-rata dari angka-angka adalah: $average"
else
    echo "Tidak ada angka yang valid dimasukkan."
fi
