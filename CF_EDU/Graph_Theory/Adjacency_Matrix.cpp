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
        vector<vector<int>> mat(n, vector<int> (n));
        vector<int> out(n, 0);
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            mat[u][v] = 1; mat[v][u] = 1;
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << mat[i][j] << ' ';
            }
            cout << "\n";
        }
    } 

    return 0;
}
