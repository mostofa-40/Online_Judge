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
        vector<int> out(n, 0);
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            out[u]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (out[i] == 1) continue;
            ans += max(1, abs(out[i] - 1));  
        }
        cout << ans << '\n';
    } 

    return 0;
}
