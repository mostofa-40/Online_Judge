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
        int n, m, ans = 0;
        cin >> n >> m;
        vector<int> in(n, 0), out(n, 0);
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            out[u]++; in[v]++;
        }
        int src = 0, snk = 0;
        for (int i = 0; i < n; i++){
            if (in[i] == 0) src++;
            if (out[i] == 0) snk++; 
        }
        cout << src << ' ' << snk << '\n';
    } 

    return 0;
}
