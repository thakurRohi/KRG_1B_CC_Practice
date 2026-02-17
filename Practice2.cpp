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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<bool> used(n, false);
        long long cur = 0;

        for (int step = 0; step < n; step++) {
            int idx = -1;
            long long best = -1;
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    long long val = (cur | a[i]);
                    if (val > best) {
                        best = val;
                        idx = i;
                    }
                }
            }
            used[idx] = true;
            cur |= a[idx];
            cout << a[idx] << " ";
        }
        cout << "\n";
    }

    return 0;
}
