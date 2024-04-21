#include <iostream>
#include <vector>

using namespace std;

unsigned long long countSequences(int n) {
    if (n <= 0) return 0;

    vector<unsigned long long> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Введите длину последовательности n: ";
    cin >> n;
    unsigned long long result = countSequences(n);
    cout << "Число последовательностей нулей и единиц длины " << n << ", в которых не встречаются две идущие подряд единицы: " << result << endl;
    return 0;
}
