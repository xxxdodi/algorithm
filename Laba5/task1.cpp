#include <iostream>
#include <queue>
#include <set>

using namespace std;

vector<int> generateNumbers(int n) {
    if (n <= 0) return {};

    vector<int> result;
    queue<int> q2, q3, q5;
    set<int> s;

    q2.push(2);
    q3.push(3);
    q5.push(5);
    s.insert(2);
    s.insert(3);
    s.insert(5);

    while (n > 0) {
        int next = min(q2.front(), min(q3.front(), q5.front()));
        result.push_back(next);
        if (next == q2.front()) {
            q2.pop();
            q2.push(next * 2);
            q3.push(next * 3);
            q5.push(next * 5);
        } else if (next == q3.front()) {
            q3.pop();
            q3.push(next * 3);
            q5.push(next * 5);
        } else {
            q5.pop();
            q5.push(next * 5);
        }
        if (!s.count(next * 2)) {
            s.insert(next * 2);
            q2.push(next * 2);
        }
        n--;
    }

    return result;
}

int main() {
    int n;
    cout << "Введите количество чисел для генерации: ";
    cin >> n;
    vector<int> numbers = generateNumbers(n);
    cout << "Первые " << n << " натуральных чисел с простыми множителями 2, 3 и 5: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
