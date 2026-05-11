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
        vector<int> a(n), b(m), c(m + n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        int i = 0, j = 0, k = 0;
        while (i < n || j < m){
            if (j == m || (i < n && a[i] < b[j])){
                c[k++] = a[i++];
            } else {
                c[k++] = b[j++];
            }
        }
        for (auto x : c) cout << x << ' '; 
        cout << '\n';
    } 

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;
//     vector<long long> v(n), vv(m), ans(n + m);
//     for (int i = 0; i < n; i++) cin >> v[i];
//     for (int i = 0; i < m; i++) cin >> vv[i];
//     int l = 0, r = 0, idx = 0; 
//     while (l < n && r < m) {
//         if (v[l] < vv[r]) {
//             ans[idx++] = v[l++];
//         } 
//         else {
//             ans[idx++] = vv[r++];
//         }
//     } 
//     while (l < n) ans[idx++] = v[l++];
//     while (r < m) ans[idx++] = vv[r++];
//     for (auto x : ans) cout << x << ' ';
//     cout << '\n';

//     return 0;
// }

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
//         vector<int> a(n), b(m), c(m + n);
//         for (int i = 0; i < n; i++) cin >> a[i];
//         for (int i = 0; i < m; i++) cin >> b[i];
//         a.push_back(INT_MAX);
//         b.push_back(INT_MAX);
//         int i = 0, j = 0, k = 0;
//         while (i < n || j < m){
//             if (a[i] < b[j]){
//                 c[k++] = a[i++];
//             } else {
//                 c[k++] = b[j++];
//             }
//         }
//         for (auto x : c) cout << x << ' '; 
//         cout << '\n';
//     } 

//     return 0;
// }
