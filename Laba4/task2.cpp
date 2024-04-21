#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> longestIncreasingSubsequence(const vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    int maxLen = 1;
    int endIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
                if (dp[i] > maxLen) {
                    maxLen = dp[i];
                    endIndex = i;
                }
            }
        }
    }

    vector<int> result;
    while (endIndex != -1) {
        result.push_back(nums[endIndex]);
        endIndex = prev[endIndex];
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> nums = {3, 4, -1, 0, 6, 2, 3};
    vector<int> lis = longestIncreasingSubsequence(nums);
    cout << "Самая длинная строго возрастающая подпоследовательность: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
