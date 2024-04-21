#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Создание пустой очереди целых чисел
    queue<int> myQueue;

    // Добавление элементов в очередь
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Печать элементов очереди
    cout << "Элементы очереди: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " "; // Выводим первый элемент
        myQueue.pop(); // Удаляем первый элемент
    }
    cout << endl;

    return 0;
}
