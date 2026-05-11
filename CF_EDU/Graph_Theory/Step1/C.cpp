#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(k, 0);
        for (int i = 0; i < k; i++) cin >> a[i];
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());

        auto has_edge = [&](int u, int v) {
            return binary_search(adj[u].begin(), adj[u].end(), v);
        };

        auto is_path = [&](){
            for (int i = 1; i < k; i++){
                if (!has_edge(a[i-1], a[i])) return false;
            }
            return true;
        };

        auto is_simple_path = [&](){
            set<int> st(all(a));
            return (int)st.size() == k;
        };

        auto is_cycle = [&](){
            if (k < 3) return false;
            return a[0] == a[k - 1];
        };

        auto is_simple_cycle = [&](){
            if (k < 3) return false;
            if (a[0] != a[k - 1]) return false;
            set<int> st;
            for (int i = 1; i < k - 1; i++){
                if (a[i] == a[0]) return false;
                st.insert(a[i]);
            }
            return (int)st.size() == (k - 2);
        };

        if (is_path()){
            if (is_cycle()){
                if (is_simple_cycle()) cout << "simple cycle\n";
                else cout << "cycle\n";
            }
            else if (is_simple_path()) cout << "simple path\n";
            else cout << "path\n";
        }
        else cout << "none\n";
    } 

    return 0;
}
