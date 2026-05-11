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
        vector<int> d(n, 0);
        vector<pair<int, int>> e;
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            d[u]++; d[v]++;
            e.push_back({u, v});
        }
        ll ans = 0;
        for (int i = 0; i < n; i++){
            ans += (1LL * d[i] * (d[i] - 1)) / 2;
        }
        vector<vector<int>> aa(n);
        for (auto &[x, y] : e){
            if (d[y] < d[x]) aa[y].push_back(x);
            else if (d[y] == d[x] && y < x) aa[y].push_back(x);
            else aa[x].push_back(y);
        }
        ll cnt = 0;
        vector<int> track(n, -1);
        for (int i = 0; i < n; i++){
            for (auto x : aa[i]) track[x] = i;
            for (auto x : aa[i]){
                for (auto y : aa[x]){
                    if (track[y] == i) cnt++;
                }
            }
        }
        ans -= (3LL * cnt);
        cout << ans << '\n';
    } 

    return 0;
}
