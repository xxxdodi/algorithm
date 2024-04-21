#include <iostream>
#include <vector>

using namespace std;

// Функция для печати матрицы
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }
}

// Функция для выполнения элементарных преобразований над строками
void rowOperation(vector<vector<double>>& matrix, int i, int j, double factor) {
    int n = matrix[0].size();
    for (int k = 0; k < n; ++k) {
        matrix[i][k] -= factor * matrix[j][k];
    }
}

// Функция для поиска обратной матрицы методом Гаусса
vector<vector<double>> inverseMatrix(vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<vector<double>> inverse(n, vector<double>(n, 0));

    // Инициализация обратной матрицы как единичной
    for (int i = 0; i < n; ++i) {
        inverse[i][i] = 1;
    }

    // Прямой ход метода Гаусса
    for (int i = 0; i < n; ++i) {
        double pivot = matrix[i][i];
        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i] / pivot;
            rowOperation(matrix, j, i, factor);
            rowOperation(inverse, j, i, factor);
        }
    }

    // Обратный ход метода Гаусса
    for (int i = n - 1; i >= 0; --i) {
        double pivot = matrix[i][i];
        for (int j = i - 1; j >= 0; --j) {
            double factor = matrix[j][i] / pivot;
            rowOperation(matrix, j, i, factor);
            rowOperation(inverse, j, i, factor);
        }
    }

    // Нормализация строк обратной матрицы
    for (int i = 0; i < n; ++i) {
        double pivot = matrix[i][i];
        for (int j = 0; j < n; ++j) {
            inverse[i][j] /= pivot;
        }
    }

    return inverse;
}

int main() {
    // Пример входной матрицы
    vector<vector<double>> matrix = {{2, 1, -1},
                                      {0, -1, 2},
                                      {1, 1, 1}};

    // Печать входной матрицы
    cout << "Входная матрица:" << endl;
    printMatrix(matrix);

    // Поиск обратной матрицы
    vector<vector<double>> inverse = inverseMatrix(matrix);

    // Печать обратной матрицы
    cout << "Обратная матрица:" << endl;
    printMatrix(inverse);

    return 0;
}
