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
        vector<int> a(n, 0);
        vector<ll> d(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++){
            int l, r;
            cin >> l >> r;
            l--;
            d[l] += 1;
            if (r < n) d[r] -= 1;
        }
        for (int i = 1; i < n; i++) d[i] += d[i - 1];
        sort(all(a));
        sort(all(d));
        ll sum = 0;
        for (int i = 0; i < n; i++) sum += (1LL * a[i] * d[i]);
        cout << sum << '\n';
    } 

    return 0;
}
