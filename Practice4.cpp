#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point {
    ll x, y;
};

ll cross(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<Point> poly(n);
    for (int i = 0; i < n; i++) cin >> poly[i].x >> poly[i].y;

    cin >> m;
    vector<Point> pts(m);
    for (int i = 0; i < m; i++) cin >> pts[i].x >> pts[i].y;

    for (int i = 0; i < m; i++) {
        bool inside = true;
        for (int j = 0; j < n; j++) {
            Point a = poly[j];
            Point b = poly[(j + 1) % n];
            if (cross(a, b, pts[i]) <= 0) {
                inside = false;
                break;
            }
        }
        if (!inside) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
