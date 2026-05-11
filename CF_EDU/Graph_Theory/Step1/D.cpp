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
        set<int> s;
        for (int i = 0; i < k; i++){
            int val; cin >> val;
            s.insert(val);
        }
        bool f = true;
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            if (s.count(u) != s.count(v)) f = false;
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    } 

    return 0;
}
