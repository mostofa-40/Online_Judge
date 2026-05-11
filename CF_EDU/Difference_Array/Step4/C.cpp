#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<ll> findPrefixSums(vector<ll>& a) {
    ll n = a.size();
    vector<ll> prefixSums(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        prefixSums[i + 1] = prefixSums[i] + a[i];
    }
    return prefixSums;
}

vector<ll> findDiffsArray(vector<ll>& arr) {
    ll n = arr.size();
    vector<ll> diffs(n);
    diffs[0] = arr[0];
    for (ll i = 1; i < n; i++) {
        diffs[i] = arr[i] - arr[i - 1];
    }
    return diffs;
}

vector<vector<ll>> precalc(vector<vector<ll>>& a) {
    ll n = a.size();
    ll m = a[0].size();
    vector<vector<ll>> rowDiffs(n, vector<ll>(m));
    for (ll i = 0; i < n; i++) {
        rowDiffs[i] = findDiffsArray(a[i]);
    }
    vector<vector<ll>> diffs2D(n, vector<ll>(m));
    for (ll j = 0; j < m; j++) {
        vector<ll> col(n);
        for (ll i = 0; i < n; i++) col[i] = rowDiffs[i][j];
        vector<ll> colDiff = findDiffsArray(col);
        for (ll i = 0; i < n; i++) diffs2D[i][j] = colDiff[i];
    }
    return diffs2D;
}

vector<vector<ll>> findPrefixSums2D(vector<vector<ll>>& a) {
    ll n = a.size();
    ll m = a[0].size();
    vector<vector<ll>> prefixSum1D(n);
    for (ll i = 0; i < n; i++) {
        prefixSum1D[i] = findPrefixSums(a[i]);
    }
    vector<vector<ll>> prefixSum2D(n + 1, vector<ll>(m + 1, 0));
    for (ll j = 0; j <= m; j++) {
        for (ll i = 0; i < n; i++) {
            prefixSum2D[i + 1][j] = prefixSum2D[i][j] + prefixSum1D[i][j];
        }
    }
    return prefixSum2D;
}

// [lx, rx) * [ly, ry) += d
void addOnHalfRectangle (ll lx, ll ly, ll rx, ll ry, ll d, vector<vector<ll>>& diffs) {
    ll n = diffs.size();
    ll m = diffs[0].size();
    if (lx < n && ly < m) diffs[lx][ly] += d;
    if (lx < n && ry < m) diffs[lx][ry] -= d;
    if (rx < n && ly < m) diffs[rx][ly] -= d;
    if (rx < n && ry < m) diffs[rx][ry] += d;
}

vector<vector<ll>> postcalc(vector<vector<ll>>& diffs){
    vector<vector<ll>> finalArr = findPrefixSums2D(diffs);
    finalArr.erase(finalArr.begin());
    for (size_t i = 0; i < finalArr.size(); i++) {
        finalArr[i].erase(finalArr[i].begin());
    }
    return finalArr;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    for (ll tc = 1; tc <= t; tc++){
        ll n, m; 
        cin >> n >> m;
        vector<vector<ll>> grid(n, vector<ll>(m, 0));
        for (ll i = 0; i < n; i++){
            for (ll j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        grid = precalc(grid);
        ll q; 
        cin >> q;
        while (q--){
            ll lx, ly, rx, ry, d;
            cin >> lx >> ly >> rx >> ry >> d;
            addOnHalfRectangle(lx - 1, ly - 1, rx, ry, d, grid);
        }
        grid = postcalc(grid);
        for (ll i = 0; i < n; i++){
            for (ll j = 0; j < m; j++){
                cout << grid[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
