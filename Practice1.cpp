#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> b(n + 2), diff(n + 3);
    for (int i = 1; i <= n; i++) cin >> b[i];

    long long ans = 0, cur = 0, window = 0;

    for (int i = 1; i <= n; i++) {
        window += diff[i];
        cur += window;

        if (cur < b[i]) {
            long long need = b[i] - cur;
            ans += need;
            cur += need;
            window += need;
            if (i + k <= n) diff[i + k] -= need;
        }
    }

    cout << ans << "\n";
    return 0;
}
