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
            double cnt = 0.0;
            for (int i = 1; i <= n; i++){
                cnt += (1.0 / (d[i] + 1));
            }
            return (ll)round(cnt);
        };
        auto ans = complete_graph();
        cout << ans << '\n';
    } 

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define all(x) (x).begin(), (x).end()
// using ll = long long;
 
// void dfs (int u, vector<bool> &vis, vector<vector<int>> &a){
//     vis[u] = true;
//     for (auto v : a[u]){
//         if (!vis[v]) dfs(v, vis, a);
//     }
// }
 
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
 
//     int t = 1;
//     cin >> t;
//     for (int tc = 1; tc <= t; tc++){
//         int n, m, ans = 0;
//         cin >> n >> m;
//         vector<vector<int>> a(n + 1);
//         for (int i = 0; i < m; i++){
//             int u, v;
//             cin >> u >> v;
//             a[u].push_back(v);
//             a[v].push_back(u);
//         }
//         vector<bool> vis(n + 1, false);
//         for (int i = 1; i <= n; i++){
//             if (!vis[i]){
//                 dfs(i, vis, a);
//                 ans++;
//             }
//         }
//         cout << ans << '\n';
//     } 
 
//     return 0;
// }
