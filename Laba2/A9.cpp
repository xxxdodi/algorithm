#include <iostream>
#include <vector>

// Функция для нахождения максимального числа в массиве
int findMax(std::vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Функция для выполнения сортировки подсчетом по указанному разряду
void countSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // Подсчет количества встречающихся цифр
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Изменение count[i] так, чтобы count[i] содержал позицию цифры в output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Построение выходного массива
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Копирование отсортированного массива в arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Функция для сортировки массива методом поразрядной сортировки
void radixSort(std::vector<int>& arr) {
    int max = findMax(arr);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
