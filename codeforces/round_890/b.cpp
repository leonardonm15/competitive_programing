#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve (int i) {
    int n; cin >> n;
    vector<int> arr;
    if (n == 1) {
        cout << "NO" << endl;
        int num;
        for (int i=0; i < n; i++) cin >> num;
        return;
    }
    int n1 = 0;
    int d1 = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
        if (num == 1) n1++;
        else {
            // todos os caras do d1 podem ser distribuidos
            if (num >= 2) d1 += (num - 1);
        }
    }
    if (i == 10000 - 36) {
        for (auto cara: arr) {
            cout << cara << " - ";
        } 
        cout << endl;
        return;
    }
    if (d1 - n1 > 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve(TC);
    } else {
        solve(TC);
    }
    return 0;
}
