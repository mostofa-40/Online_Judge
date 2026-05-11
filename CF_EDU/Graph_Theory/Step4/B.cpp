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
        int n;
        cin >> n;
        vector<vector<int>> mat(n, vector<int> (n));
        vector<int> d(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> mat[i][j];
                d[i] += (mat[i][j] == 1);
            }  
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] != mat[j][i]){
                    cout << "NO\n"; 
                    goto sesh;
                }
                else if (i == j && mat[i][j] == 1){
                    cout << "NO\n"; 
                    goto sesh;
                }
            }
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << d[i] << ' '; 
        cout << '\n';
        sesh:;
    } 

    return 0;
}
