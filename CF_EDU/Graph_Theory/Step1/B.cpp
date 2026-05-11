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
        vector<int> deg(n + 1, 0);
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            deg[u]++; deg[v]++;
        }
        for (int i = 1; i <= n; i++) cout << deg[i] << ' '; 
        cout << '\n';
    } 

    return 0;
}
