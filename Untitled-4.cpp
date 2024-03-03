#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;

int smartsumsearch(int arr[], unsigned long long size, int key)
{
    int i = 0;
    int j = size - 1;
    int f = 0;
    while (f == 0)
    {
        if (arr[i] + arr[j] > key)
        {
            j -= 1;
        }
        if (arr[i] + arr[j] < key)
        {
            i += 1;
        }
        if (arr[i] + arr[j] == key)
        {
            return i + j;
        }
        if (i == j)
        {
            return -1;
        }
    }
    return -100;
}

int getRandomNumber(int min, int max){
    const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main ( ) {
for (int size = 10; size <= 100000; size += 1000){
    int *arr = new int[size];
    for (int i = 0; i < size; i++){
        arr[i] = getRandomNumber(1, size);
    }    
    for (int i = 0; i < size; i++) {
    for (int j = 0; j < size-1; j++) {
      if (arr[j] > arr[j + 1]) {
        int b = arr[j]; // создали дополнительную переменную
        arr[j] = arr[j + 1]; // меняем местами
        arr[j + 1] = b; // значения элементов

      }
    }
  }
    long long summ = 0;
    int kolvo = 5000;
    for (int k = 0; k< kolvo; k++){
        auto begin = std::chrono::steady_clock::now( ); 
        int o = smartsumsearch(arr, size, getRandomNumber(1, size));
        auto end = std::chrono::steady_clock::now( );
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        summ += elapsed_ms.count();
    }
    cout << size << ";" << summ / kolvo << endl;
}
return 0;
}