#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int findLargestMobile(const vector<int>& permutation, const vector<int>& direction) {
    int maxMobile = -1;
    int n = permutation.size();
    for (int i = 0; i < n; ++i) {
        if ((i == 0 && direction[i] == -1) || // Если это первый элемент и он направлен влево
            (i == n - 1 && direction[i] == 1)) { // Если это последний элемент и он направлен вправо
            continue; // Пропускаем этот элемент
        }

        // Проверяем, является ли текущий элемент мобильным
        if (permutation[i] > permutation[i + direction[i]] && permutation[i] > maxMobile) {
            maxMobile = permutation[i];
        }
    }
    return maxMobile;
}

void performStep(vector<int>& permutation, vector<int>& direction, int mobile) {
    int n = permutation.size();
    int index = find(permutation.begin(), permutation.end(), mobile) - permutation.begin();
    swap(permutation[index], permutation[index + direction[index]]);
    swap(direction[index], direction[index + direction[index]]);

    for (int i = 0; i < n; ++i) {
        if (permutation[i] > mobile) {
            direction[i] *= -1;
        }
    }
}

void generatePermutations(int n) {
    vector<int> permutation(n);
    vector<int> direction(n, -1);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1; 
    }

    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;

    while (true) {
        int mobile = findLargestMobile(permutation, direction);
        if (mobile == -1) {
            break;
        }
        performStep(permutation, direction, mobile);

        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите число элементов (n): ";
    cin >> n;
    cout << "Все перестановки из " << n << " элементов с минимальными изменениями:" << endl;
    generatePermutations(n);
    return 0;
}
