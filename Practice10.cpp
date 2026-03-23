#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w, idx;
};

const int N = 200005;

int parent[N], sz[N];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

vector<pair<int,int>> g[N];
int tin[N], low[N], timer;
bool used[N];
map<pair<int,int>, vector<int>> edge_ids;

void dfs(int v, int p) {
    used[v] = true;
    tin[v] = low[v] = timer++;
    for (auto [to, id] : g[v]) {
        if (id == p) continue;
        if (used[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, id);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                for (auto eid : edge_ids[{v, to}]) {
                    // mark later
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; edges[i].v--;
        edges[i].idx = i;
    }

    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
        return a.w < b.w;
    });

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    vector<string> ans(m);

    int i = 0;
    while (i < m) {
        int j = i;
        while (j < m && edges[j].w == edges[i].w) j++;

        map<int,int> comp;
        int id = 0;

        for (int k = i; k < j; k++) {
            int u = find_set(edges[k].u);
            int v = find_set(edges[k].v);
            if (u == v) {
                ans[edges[k].idx] = "none";
            } else {
                if (!comp.count(u)) comp[u] = id++;
                if (!comp.count(v)) comp[v] = id++;
            }
        }

        for (int k = 0; k < id; k++) {
            g[k].clear();
            used[k] = false;
        }
        edge_ids.clear();

        int eid = 0;

        for (int k = i; k < j; k++) {
            int u = find_set(edges[k].u);
            int v = find_set(edges[k].v);
            if (u == v) continue;
            int cu = comp[u], cv = comp[v];
            g[cu].push_back({cv, eid});
            g[cv].push_back({cu, eid});
            edge_ids[{cu, cv}].push_back(edges[k].idx);
            edge_ids[{cv, cu}].push_back(edges[k].idx);
            eid++;
        }

        timer = 0;

        function<void(int,int)> dfs2 = [&](int v, int p) {
            used[v] = true;
            tin[v] = low[v] = timer++;
            for (auto [to, idd] : g[v]) {
                if (idd == p) continue;
                if (used[to]) {
                    low[v] = min(low[v], tin[to]);
                } else {
                    dfs2(to, idd);
                    low[v] = min(low[v], low[to]);
                    if (low[to] > tin[v]) {
                        for (auto idx : edge_ids[{v, to}]) {
                            ans[idx] = "any";
                        }
                    }
                }
            }
        };

        for (int k = 0; k < id; k++) {
            if (!used[k]) dfs2(k, -1);
        }

        for (int k = i; k < j; k++) {
            if (ans[edges[k].idx] == "") {
                int u = find_set(edges[k].u);
                int v = find_set(edges[k].v);
                if (u != v) ans[edges[k].idx] = "at least one";
            }
        }

        for (int k = i; k < j; k++) {
            union_set(edges[k].u, edges[k].v);
        }

        i = j;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}