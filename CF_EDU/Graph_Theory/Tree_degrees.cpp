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
        ll n;
        cin >> n;
        ll sum = 0;
        bool f = true;
        for (int i = 0; i < n; i++){
            ll val; 
            cin >> val; 
            sum += val;
            if (val == 0) f = false;
        }
        if (n == 1){
            cout << ((sum == 0) ? "YES\n" : "NO\n");
            continue;
        }
        if (sum != (2 * (n - 1))) f = false;
        cout << (f ? "YES\n" : "NO\n");
    } 

    return 0;
}
