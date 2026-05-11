#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int x = 1e6 + 5;
int  cnt[x];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++){
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++){
            int val; 
            cin >> val;
            cnt[val] = 1;
        }
        for (int i = 1; i < x; i++) cnt[i] += cnt[i - 1];
        int ans = 0, req = max(0, (k - m));
        for (int i = k; i <= (1e6); i++){
            if ((cnt[i] - cnt[i - k]) >= req) ans++;
        }
        cout << ans << '\n';
    } 

    return 0;
}
