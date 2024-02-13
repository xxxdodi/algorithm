#include <iostream>
#include <string>

using namespace std;

void generateBinarySequences(int n, string sequence) {
    if (n == 0) {
        cout << sequence << endl;
        return;
    }
    generateBinarySequences(n - 1, sequence + "0");
    generateBinarySequences(n - 1, sequence + "1");
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите длину последовательности (n): ";
    cin >> n;

    string sequence = "";

    cout << "Все последовательности длины " << n << " в лексикографическом порядке:" << endl;
    generateBinarySequences(n, sequence);

    return 0;
}
