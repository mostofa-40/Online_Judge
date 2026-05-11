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
        int n, k;
        cin >> n >> k;
        // Handshaking Lemma 2e = n*k
        if (((n * k) & 1) || k >= n){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<pair<int, int>> a, ans;
        for (int i = 1; i <= n; i++){
            a.push_back({k, i});
        }
        auto havel_hakimi = [&](){
            while (!a.empty()){
                sort(a.rbegin(), a.rend());
                int d = a[0].first, node = a[0].second;
                a.erase(a.begin());
                if (d > (int)a.size()) break;
                for (int i = 0; i < d; i++){
                    ans.push_back({node, a[i].second});
                    a[i].first--;
                }
                vector<pair<int, int>> aa;
                for (auto &[x, y] : a){
                    if (x > 0) aa.push_back({x, y});
                }
                a = aa;
            }
        };
        havel_hakimi();
        cout << (int)ans.size() << '\n';
        for (auto &[x, y] : ans) cout << x << ' ' << y << '\n';
    } 

    return 0;
}
