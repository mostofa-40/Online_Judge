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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<tuple<int, int, ll>> v(m + 1);
        for (int i = 1; i <= m; i++){
            int l, r; ll d;
            cin >> l >> r >> d;
            v[i] = make_tuple(l, r, d);
        }
        vector<ll> d(m + 2, 0);
        for (int i = 0; i < k; i++){
            int l, r;
            cin >> l >> r;
            d[l] += 1;
            d[r + 1] -= 1;
        }
        for (int i = 1; i <= m; i++) d[i] += d[i - 1];
        for (int i = 1; i <= m; i++){
            auto &[x, y, z] = v[i];
            z = (d[i] * z);
        }
        vector<ll> diff(n + 2, 0);
        for (int i = 1; i <= m; i++){
            auto &[x, y, z] = v[i];
            diff[x] += z;
            diff[y + 1] -= z;
        }
        for (int i = 1; i <= n; i++) diff[i] += diff[i - 1];
        for (int i = 1; i <= n; i++) cout << (ll)(a[i] + diff[i]) << ' ';
    }

    return 0;
}
