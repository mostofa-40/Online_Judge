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
        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int x; cin >> x;
                if (x == 1){
                    cout << j + 1 << ' ';
                }
            }
            cout << '\n';
        }
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
//     cin >> t;
//     for (int tc = 1; tc <= t; tc++){
//         int n;
//         cin >> n;
//         vector<vector<int>> a(n);
//         for (int i = 0; i < n; i++){
//             for (int j = 0; j < n; j++){
//                 int x; cin >> x;
//                 if (x == 1){
//                     a[i].push_back(j);
//                     // a[j].push_back(i);
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++){
//             for (auto x : a[i]){
//                 cout << x + 1 << ' ';
//             }
//             cout << '\n';
//         }
//     } 

//     return 0;
// }
