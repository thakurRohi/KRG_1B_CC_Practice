#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (a[i] <= n) freq[a[i]]++;
        }

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + a[i];
        }

        vector<bool> good(n + 1, false);
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int sum = prefix[r + 1] - prefix[l];
                if (sum > n) break;
                good[sum] = true;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (good[i]) ans += freq[i];
        }

        cout << ans << "\n";
    }

    return 0;
}
