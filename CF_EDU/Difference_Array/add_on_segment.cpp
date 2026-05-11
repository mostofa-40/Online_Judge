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
        int n; 
        cin >> n;
        vector<ll> a(n + 1, 0), diff(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        int q; 
        cin >> q;
        while (q--){
            int l, r; ll d;
            cin >> l >> r >> d;
            l--; r--;
            diff[l] += d; diff[r + 1] -= d;
        }
        for (int i = 1; i <= n; i++) diff[i] += diff[i - 1];
        for (int i = 0; i < n; i++) cout << a[i] + diff[i] << ' '; 
        cout << '\n';
    }

    return 0;
}
