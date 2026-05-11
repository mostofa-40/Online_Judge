#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<ll> findPrefixSums(vector<ll>& a){
    ll n = a.size();
    vector<ll> prefixSums(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        prefixSums[i + 1] = prefixSums[i] + a[i];
    }
    return prefixSums;
}

vector<ll> findDiffsArray(vector<ll>& arr){
    ll n = arr.size();
    vector<ll> diffs(n - 1);
    for (ll i = 0; i < n - 1; i++){
        diffs[i] = arr[i + 1] - arr[i];
    }
    return diffs;
}

vector<ll> precalc(vector<ll> b){
    b.insert(b.begin(), 0);
    b.insert(b.begin(), 0); // add two leading zeros
    // vector<ll> a = findDiffsArray(findDiffsArray(b));
    vector<ll> temp = (findDiffsArray(b));
    vector<ll> a = (findDiffsArray(temp));
    return a;
}

// [l, r) += [step, 2 * step, ..., (r - l) * step]
void addArithmOnHalfllerval(ll l, ll r, ll step, vector<ll>& a){
    ll n = a.size();
    a[l] += step;
    if (r < n) {
        a[r] -= (r - l + 1) * step;
    }
    if (r + 1 < n) {
        a[r + 1] += (r - l) * step;
    }
}

vector<ll> postcalc(vector<ll>& a){
    // vector<ll> finalB = findPrefixSums(findPrefixSums(a));
    vector<ll> temp = findPrefixSums(a); 
    vector<ll> finalB = findPrefixSums(temp);
    finalB.erase(finalB.begin());
    finalB.erase(finalB.begin()); // delete leading zeros
    return finalB;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    for (ll tc = 1; tc <= t; tc++){
        ll n; 
        cin >> n;
        vector<ll> a(n, 0);
        for (ll i = 0; i < n; i++) cin >> a[i];
        a = precalc(a);
        ll q; 
        cin >> q;
        while (q--){
            ll l, r, d;
            cin >> l >> r >> d;
            addArithmOnHalfllerval(l - 1, r, d, a);
        }
        a = postcalc(a);
        for (ll i = 0; i < n; i++) cout << a[i] << ' '; 
        cout << '\n';
    }

    return 0;
}
