#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<ll> findPrefixSums(vector<ll>& a){
    int n = a.size();
    vector<ll> prefixSums(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSums[i + 1] = (prefixSums[i] ^ a[i]);
    }
    return prefixSums;
}

ll getSum(int left, int right, vector<ll>& b){ // [left, right)
    return (b[right] ^ b[left]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++){
        int n; 
        cin >> n;
        vector<ll> a(n), p(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        p = findPrefixSums(a);
        int q; 
        cin >> q;
        while (q--){
            int l, r; cin >> l >> r;
            cout << getSum(l - 1, r, p) << '\n';
        }
    }

    return 0;
}
