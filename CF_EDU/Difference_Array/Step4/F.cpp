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
        vector<int> a(n + 1, 0);
        vector<ll> aa(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<pair<int, int>> d(n + 2);
        vector<pair<int, int>> v(m + 1);
        for (int i = 1; i <= m; i++){
            int l, r;
            cin >> l >> r;
            v[i] = {l , r};
            d[l].first += 1;
            d[r + 1].first -= 1;
        }
        for (int i = 1; i <= n; i++) d[i].first += d[i - 1].first;
        for (int i = 1; i <= n; i++) d[i].second = i;
        sort(d.begin() + 1, d.begin() + n + 1);
        sort(all(a));
        for (int i = n; i >= 1; i--) aa[d[i].second] = a[i];         
        for (int i = 1; i <= n; i++) aa[i] += aa[i - 1];
        ll ans = 0;
        for (int i = 1; i <= m; i++){
            auto &[l, r] = v[i];
            ans += (aa[r] - aa[l - 1]);
        }
        cout << ans << '\n';
    } 

    return 0;
}
