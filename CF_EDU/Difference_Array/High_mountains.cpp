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
        cin >> n;
        vector<ll> a(n, 0), d(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        reverse(all(a));
        cin >> m;
        for (int i = 0; i < m; i++){
            int x, val;
            cin >> x >> val;
            d[0] += val;
            if (x < n) d[x] -= val;
        }
        for (int i = 1; i < n; i++) d[i] += d[i - 1];
        for (int i = 0; i < n; i++) a[i] += d[i];
        reverse(all(a));
        for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << '\n';
    } 

    return 0;
}
