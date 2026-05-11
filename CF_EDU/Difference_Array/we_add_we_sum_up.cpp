#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int n = 1 << 24;
unsigned int d[n + 5];
int m, q;
unsigned int a, b, l, r, adding; 
unsigned int cur = 0; 
unsigned int nextRand() {
    cur = cur * a + b;
    return cur >> 8; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++){
        cin >> m >> q >> a >> b;
        for (int i = 0; i < m; i++){
            adding = nextRand(); 
            l = nextRand() + 1;
            r = nextRand() + 1;
            if (l > r) swap(l, r); 
            d[l] += adding;
            d[r + 1] -= adding;
        }
        for (int i = 1; i <= n; i++) d[i] += d[i - 1];
        for (int i = 1; i <= n; i++) d[i] += d[i - 1];
        unsigned int sum = 0;
        for (int i = 0; i < q; i++){
            l = nextRand() + 1;
            r = nextRand() + 1;
            if (l > r) swap(l, r); 
            sum += (d[r] - d[l - 1]);
        }
        cout << sum << '\n';
    } 

    return 0;
}
