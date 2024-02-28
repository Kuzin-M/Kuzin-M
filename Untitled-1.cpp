#include <iostream>
#include <random>
#include <chrono>


using namespace std;

int getRandomNumber(int min, int max)
{
    const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void func ( ) {
cout << " H ell o ␣ world " << endl ;
 }

// void print_arr(int a(*)[], int n){
//     for (int i=0; i<n;i++){
//           for (int j=0;j<n;j++){
//             cout << a[i][j]<<" ";
//         }
//         cout << "\n";
//     }
// }


int main(){
    int n = getRandomNumber(3, 10);
    int a[n][n];
    for (int i=0; i<n;i++){
        for (int j=0;j<n;j++){
            a[i][j] = getRandomNumber(0, 1);
            cout << a[i][j];
        }
    }
//     print_arr(a, n);


}