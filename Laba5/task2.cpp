#include <iostream>
#include <list>

using namespace std;

// Функция для печати списка
void printList(const list<int>& myList) {
    for (int elem : myList) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    // Начальное формирование списка
    list<int> myList = {1, 2, 3, 4, 5};

    // Печать начального списка
    cout << "Начальный список: ";
    printList(myList);

    // Добавление элемента в конец списка
    int newElement = 6;
    myList.push_back(newElement);

    // Печать списка после добавления элемента
    cout << "Список после добавления элемента " << newElement << " в конец: ";
    printList(myList);

    return 0;
}
