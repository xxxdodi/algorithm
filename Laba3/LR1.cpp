#include <iostream>
using namespace std;
#include <iostream>
#include <algorithm>

int poiskLin(int *a, int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

int main() {
    int arr[] = {8, 3, 5, 2, 4, 1, 9, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    std::cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) 
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    
    int key = 5; // элемент, который мы ищем

    std::cout << "Результат поиска: " << poiskLin(arr, n, key) << std::endl;

    return 0;
}
