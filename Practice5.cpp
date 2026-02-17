#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll s;
    cin >> n >> s;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto can = [&](int k, ll &cost) {
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] + 1LL * (i + 1) * k;
        }
        sort(b.begin(), b.end());
        ll sum = 0;
        for (int i = 0; i < k; i++) sum += b[i];
        cost = sum;
        return sum <= s;
    };

    int l = 0, r = n, ans = 0;
    ll best = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        ll cost = 0;
        if (can(mid, cost)) {
            ans = mid;
            best = cost;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << " " << best << "\n";

    return 0;
}
