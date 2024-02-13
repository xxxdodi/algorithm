#include <iostream>
#include <vector>

using namespace std;

void generateSequencesUtil(vector<int>& sequence, int n, int k, int changesLeft) {
    if (sequence.size() == n) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < k; ++i) {
        if (changesLeft > 0) {
            sequence.push_back(i);
            generateSequencesUtil(sequence, n, k, changesLeft - 1);
            sequence.pop_back(); // Возвращаемся к предыдущему состоянию
        }
        else {
            if (!sequence.empty() && sequence.back() == i) {
                sequence.push_back(i);
                generateSequencesUtil(sequence, n, k, changesLeft);
                sequence.pop_back();
            }
        }
    }
}

void generateSequences(int n, int k) {
    vector<int> sequence;
    generateSequencesUtil(sequence, n, k, 1); 
}

int main() {
    setlocale(LC_ALL, "ru");
    int n, k;
    cout << "Введите длину последовательности (n): ";
    cin >> n;
    cout << "Введите значение k: ";
    cin >> k;
    cout << "Все последовательности длины " << n << " из чисел 0,1,...," << k - 1 << " с минимальными изменениями:" << endl;
    generateSequences(n, k);
    return 0;
}
