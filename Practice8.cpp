#include <bits/stdc++.h>
using namespace std;

int parent[200001], sz[200001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b, int &components, int &maxSize) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        maxSize = max(maxSize, sz[a]);
        components--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    int components = n;
    int maxSize = 1;

    while (m--) {
        int a, b;
        cin >> a >> b;
        unite(a, b, components, maxSize);
        cout << components << " " << maxSize << "\n";
    }

    return 0;
}