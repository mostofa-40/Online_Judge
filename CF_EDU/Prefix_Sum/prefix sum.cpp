#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++){
        int n; 
        cin >> n;
        vector<ll> a(n), p(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];
        for (int i = 0; i <= n; i++) cout << p[i] << ' '; 
        cout << '\n';
    }

    return 0;
}
