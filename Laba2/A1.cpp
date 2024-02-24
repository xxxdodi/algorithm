#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector <int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}


int main() {

    setlocale(LC_ALL, "ru");
    vector <int> arr = { 1,59,123,2,4 };

    cout << "Исходный: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    selectionSort(arr);

    cout << "После сортировки: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
