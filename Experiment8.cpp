#include <bits/stdc++.h>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maxVal = 0;

        // Try all partition sizes ending at index i
        for (int len = 1; len <= k && i - len >= 0; len++) {
            maxVal = max(maxVal, arr[i - len]);
            dp[i] = max(dp[i], dp[i - len] + maxVal * len);
        }
    }

    return dp[n];
}

int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    cout << "Maximum Sum: " << maxSumAfterPartitioning(arr, k) << endl;

    return 0;
}