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
        set<pair<int, int>> s;
        bool f = true;
        while (m--){
            int u, v;
            cin >> u >> v;
            if (u == v) f = false;
            else if (s.count({v, u}) || s.count({u, v})) f = false;
            if (!f) continue;
            s.insert({u, v});
        } 
        if (f) cout << "YES\n";
        else cout << "NO\n";
    } 

    return 0;
}
