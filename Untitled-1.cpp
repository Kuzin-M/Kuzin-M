#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;

int unary(int arr[], unsigned long long size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int getRandomNumber(int min, int max){
    const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main ( ) {
for (int size = 10; size <= 1000000; size+= 10000){
    int *arr = new int[size];
    for (int i = 0; i < size; i++){
        arr[i] = getRandomNumber(1, 32000);
    }    
    long long summ = 0;
    int kolvo = 5000;
    for (int k = 0; k< kolvo; k++){
        auto begin = std::chrono::steady_clock::now( ); 
        unary(arr, size, getRandomNumber(1, 32000));
        auto end = std::chrono::steady_clock::now( );
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        summ += elapsed_ms.count();
    }
    cout << size << "," << summ / kolvo << endl;
}

return 0;
}