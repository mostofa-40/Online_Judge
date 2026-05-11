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
        vector<pair<int, int>> a, ans;
        for (int i = 1; i <= n; i++){
            int d; 
            cin >> d;
            if (d > 0) a.push_back({d, i});
        }
        auto havel_hakimi = [&](){
            while (!a.empty()){
                sort(a.rbegin(), a.rend());
                int d = a[0].first, node = a[0].second;
                a.erase(a.begin());
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
