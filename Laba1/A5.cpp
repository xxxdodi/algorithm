#include <iostream>
#include <vector>

using namespace std;

void generateCombinationsUtil(vector<int>& combination, int n, int k, int start) {
    if (combination.size() == k) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // Генерация сочетаний начиная с числа start
    for (int i = start; i <= n; ++i) {
        combination.push_back(i);
        generateCombinationsUtil(combination, n, k, i + 1); // Рекурсивный вызов для следующего элемента
        combination.pop_back(); // Удаляем последний элемент, чтобы сгенерировать следующее сочетание
    }
}

void generateCombinations(int n, int k) {
    vector<int> combination;
    generateCombinationsUtil(combination, n, k, 1); // Начинаем с числа 1
}

int main() {
    setlocale(LC_ALL, "ru");
    int n, k;
    cout << "Введите общее количество элементов (n): ";
    cin >> n;
    cout << "Введите длину сочетаний (k): ";
    cin >> k;

    if (k > n) {
        cout << "Ошибка: длина сочетаний не может быть больше общего количества элементов." << endl;
        return 1;
    }

    cout << "Все сочетания длины " << k << " из чисел от 1 до " << n << " в лексикографическом порядке:" << endl;
    generateCombinations(n, k);
    return 0;
}
