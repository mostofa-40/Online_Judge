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
        ll m;
        cin >> m;
        if (m == 0){
            cout << 0 << '\n';
            continue;
        }
        // n^2 - n - 2m = 0
        // n = (1 + sqrt(1 + 8m)) / 2
        long double D = 1.0L + 8.0L * m;
        ll det = ceill(sqrtl(D)); 
        ll n = (1LL + det + 1) / 2; 
        cout << n << '\n';
    } 

    return 0;
}
