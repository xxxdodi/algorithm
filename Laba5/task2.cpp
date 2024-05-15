#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> generateNumbers(int n) {
    vector<int> result;
    if (n <= 0) return result;

    // Используем три очереди для хранения чисел, которые делятся только на 2, 3 и 5
    queue<int> q2, q3, q5;

    // Начинаем с 1
    result.push_back(1);

    // Начальные значения для q2, q3 и q5
    q2.push(2);
    q3.push(3);
    q5.push(5);

    // Генерируем числа, пока не достигнем n
    while (result.size() < n) {
        // Берем минимальное число из трех очередей
        int next = min(q2.front(), min(q3.front(), q5.front()));

        // Добавляем это число в результат
        result.push_back(next);

        // Удаляем из очередей числа, равные next
        if (next == q2.front()) q2.pop();
        if (next == q3.front()) q3.pop();
        if (next == q5.front()) q5.pop();

        // Добавляем в очереди новые числа, умноженные на 2, 3 и 5
        q2.push(next * 2);
        q3.push(next * 3);
        q5.push(next * 5);
    }

    return result;
}

int main() {
    int n;
    cout << "Введите количество чисел для генерации: ";
    cin >> n;

    vector<int> numbers = generateNumbers(n);

    cout << "Первые " << n << " чисел, в разложении которых на простые множители встречаются только числа 2, 3 и 5:\n";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
