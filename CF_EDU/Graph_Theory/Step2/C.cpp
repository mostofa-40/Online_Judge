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
        int n, m;
        cin >> n >> m;
        vector<int> d(n + 1);
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            d[u]++; d[v]++;
        }
        auto complete_graph = [&](){
            set<int> s;
            vector<int> v;
            for (int i = 1; i <= n; i++){
                if (d[i] > 0){
                    s.insert(d[i]); v.push_back(i);
                }
            }
            if ((int)s.size() > 1) return false;
            int k = (int)v.size();
            return (k * (k - 1)) == (2 * m);
        };
        bool f = complete_graph();
        if (!f) cout << "NO\n"; 
        else cout << "YES\n";
    } 

    return 0;
}
