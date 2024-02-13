#include <iostream>
#include <vector>

using namespace std;

void generateSequences(int n, int k, vector<int>& sequence) {
    if (n == 0) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < k; i++) {
        sequence.push_back(i);
        generateSequences(n - 1, k, sequence);
        sequence.pop_back();
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n, k;
    cout << "Введите длину последовательности (n): ";
    cin >> n;
    cout << "Введите верхнюю границу чисел (k): ";
    cin >> k;

    vector<int> sequence;
    cout << "Все последовательности длины " << n << " из чисел 0-" << k - 1 << " в лексикографическом порядке:" << endl;
    generateSequences(n, k, sequence);

    return 0;
}
