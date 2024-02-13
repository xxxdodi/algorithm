#include <iostream>
#include <vector>

using namespace std;

void generateGrayCodes(int n, vector<string>& grayCodes) {
    if (n == 1) {
        grayCodes.push_back("0");
        grayCodes.push_back("1");
        return;
    }

    generateGrayCodes(n - 1, grayCodes);

    int size = grayCodes.size();
    for (int i = size - 1; i >= 0; i--) {
        string code = grayCodes[i];
        grayCodes.push_back(code);
    }

    for (int i = 0; i < size; i++) {
        string code = grayCodes[i];
        grayCodes[i] = "0" + code;
        grayCodes[i + size] = "1" + code;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите длину кодов Грея (n): ";
    cin >> n;

    vector<string> grayCodes;
    generateGrayCodes(n, grayCodes);

    cout << "Все коды Грея длины " << n << ":" << endl;
    for (string code : grayCodes) {
        cout << code << endl;
    }

    return 0;
}
