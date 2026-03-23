#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> adj(26);
    vector<int> indeg(26, 0);

    for (int i = 0; i < n - 1; i++) {
        string a = v[i], b = v[i + 1];
        int len = min(a.size(), b.size());
        bool found = false;
        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                found = true;
                break;
            }
        }
        if (!found && a.size() > b.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j : adj[i]) indeg[j]++;
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    string res;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res.push_back(char('a' + u));
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    if (res.size() != 26) {
        cout << "Impossible\n";
    } else {
        cout << res << "\n";
    }

    return 0;
}