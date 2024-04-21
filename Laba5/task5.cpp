#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// Функция для печати списка
void printList(const list<int>& myList) {
    for (int elem : myList) {
        cout << elem << " ";
    }
    cout << endl;
}

// Функция для вставки элемента после элемента с заданным ключом
void insertAfterKey(list<int>& myList, int key, int value) {
    auto it = find(myList.begin(), myList.end(), key);
    if (it != myList.end()) {
        myList.insert(++it, value);
    } else {
        cout << "Ключ не найден в списке." << endl;
    }
}

int main() {
    // Создание списка
    list<int> myList = {1, 2, 3, 4, 5};

    // Печать исходного списка
    cout << "Исходный список: ";
    printList(myList);

    // Вставка элемента после элемента с заданным ключом
    int key = 3;
    int value = 100;
    insertAfterKey(myList, key, value);

    // Печать списка после вставки
    cout << "Список после вставки " << value << " после элемента с ключом " << key << ": ";
    printList(myList);

    return 0;
}
