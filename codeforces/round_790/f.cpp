#include <bits/stdc++.h>

using namespace std;
//#define int long long

bool compare(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

void solve () {
    int n, k; cin >> n >> k;
    map<int, int> map;
    set<int> set;
    
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        map[num]++;
    }
    for (auto [cara, f]: map) {
        if (f >= k) set.emplace(cara);
    }

    vector<int> arr;
    int m = 0;
    int l = 0;
    for (auto cara: set) {
        if (arr.size() == 0 || arr[arr.size() - 1] == cara + -1) {
            arr.push_back(cara);
        } else {
            if (arr.size() > 0) {
                int a = arr[0];
                int b = arr[arr.size() - 1];
                if (b - a >= m - l) {
                    l = a;
                    m = b;
                }
            }
            arr.clear();
            arr.push_back(cara);
        }
    }

    if (arr.size() > 0) {
        int a = arr[0];
        int b = arr[arr.size() - 1];
        if (b - a >= m - l) {
            l = a;
            m = b;
        }
    }

    if (m == 0 && l == 0) cout << -1 << endl;
    else cout << l << " " << m << endl;
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
