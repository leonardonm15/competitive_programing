#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    map<string, int> map;
    map["tourist"] = 3858;
    map["ksun48"] = 3679;
    map["Benq"] = 3658;
    map["Um_nik"] = 3648;
    map["apiad"] = 3638;
    map["Stonefeang"] = 3630;
    map["ecnerwala"] = 3613;
    map["mnbvmar"] = 3555;
    map["newbiedmy"] = 3516;
    map["semiexp"] = 3481;
    string n; cin >> n;
    cout << map[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
