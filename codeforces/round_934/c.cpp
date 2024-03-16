#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
const int N = 2e5 + 5;
vector<int> v(N);
void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> map;
    set<int> set;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;
        set.emplace(num);
        map[num]++;
    }

    sort(arr.begin(), arr.end());
    v[arr[0]]++;
    int l = 0;
    int r = 1;
    for (auto cara: set) {
        /* cout << "map[cara] - >" << map[cara] << endl; */
        if (map[cara] >= r) {
            v[cara]++;
        }
        else {
            /* cout << "map[cara] - > " << cara << endl; */
            /* cout << "r -> " << r << endl; */
            /* cout << "cara - > " << cara << endl; */
            break;
        }
        r++;
    }

    int i = 0;
    for (auto cara: set) {
        if (i == r) break;
        v[cara]++;
        i++;
    }

    for (int i=0; i <= n + 1; i++) {
        if (v[i] == 0) {
            cout << i << endl;
            return;
        }
    }

    for (int i=0; i <= n; i++) v[i] = 0;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
