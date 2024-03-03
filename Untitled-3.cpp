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

int binary(int arr[], unsigned long long size, int val)
{
    int l = 0, r = size - 1;

    while (r > l)
    {
        int m = (l + r) / 2;

        if (arr[m] < val)
        {
            l = m + 1;
        }
        else if (arr[m] > val)
        {
            r = m - 1;
        }
        else
        {
            return m;
        }
    }
    if (arr[l] == val)
    {
        return l;
    }
    else
    {
        return -1;
    }
}

int sumsearch(int arr[], unsigned long long size, int key)
{
    for (int i = size - 1; i > -1; i--)
    {
        if (i == 1)
        {
            return -1;
        }
        for (int j = 0; j < i; j++)
        {
            if (arr[i] + arr[j] == key)
            {
                return i + j;
            }
        }
    }
    return -1;
}

int getRandomNumber(int min, int max){
    const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main ( ) {
for (int size = 10; size <= 10000; size += 100){
    int *arr = new int[size];
    for (int i = 0; i < size; i++){
        arr[i] = getRandomNumber(1, size);
    }    
    long long summ = 0;
    int kolvo = 500;
    for (int k = 0; k< kolvo; k++){
        auto begin = std::chrono::steady_clock::now( ); 
        int o = sumsearch(arr, size, getRandomNumber(1, size));
        auto end = std::chrono::steady_clock::now( );
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        summ += elapsed_ms.count();
    }
    cout << size << ";" << summ / kolvo << endl;
}
return 0;
}