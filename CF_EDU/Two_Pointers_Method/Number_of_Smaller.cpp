#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), res(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        int i = 0;
        for (int j = 0; j < m; j++){
            while (i < n && a[i] < b[j]){
                i++;
            }
            res[j] = i;
        }
        for (auto x : res) cout << x << ' '; 
        cout << '\n';
    } 

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define all(x) (x).begin(), (x).end()
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t = 1;
//     // cin >> t;
//     for (int tc = 1; tc <= t; tc++){
//         int n, m;
//         cin >> n >> m;
//         vector<int> a(n), b(m), res(m);
//         for (int i = 0; i < n; i++) cin >> a[i];
//         for (int i = 0; i < m; i++) cin >> b[i];
//         int i = 0, j = 0;
//         while (i < n || j < m){
//             if (j == m || (i < n && a[i] < b[j])){
//                 i++;
//             } else {
//                 res[j++] = i;
//             }
//         }
//         for (auto x : res) cout << x << ' '; 
//         cout << '\n';
//     } 

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n,m;
//     cin >> n >> m;
//     vector<long long>v(n),vv(m);
//     for(int i=0; i<n; i++) cin >> v[i];
//     for(int i=0; i<m; i++) cin >> vv[i];
//     int l=0,r=0;
//     int cnt=0;
//     while(r<m){
//         if (l<n && v[l]<vv[r]){
//             cnt++;
//             l++;
//         }
//         else{
//             cout << cnt << ' ';
//             r++;
//         }
//     }
//     return 0;
// }
