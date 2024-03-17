int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (arr[middle] == key) {
            return middle;
        } else if (arr[middle] < key) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    return -1; // элемент не найден
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 11;
    int result = binarySearch(arr, n, key);
    if (result != -1) {
        cout << "Элемент найден на позиции " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    return 0;
}
