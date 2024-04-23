#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<int> bomba(1e6);
vector<int> mex(1e6);
vector<int> gn(1e6);

void calc() {
    for (int i=0; i <= 1500; i++) {
        int k = i - 1;
        int c = 1;
        while (k > c) {
            mex[gn[c] ^ gn[k]]++;
            k--;
            c++;
        }

        int resp = 0;
        for (int i=0; i <= 10000; i++) {
            if (mex[i] == 0) {
                resp = i;
                break;
            }
        }

        for (int i=0; i <= 1500; i++) mex[i] = 0;

        /* if (resp == 0) { */
        /*     /1* cout << i << " -> " << resp << endl; *1/ */
        /* } */
        gn[i] = resp;
    }
}

void solve () {
    int n; cin >> n;
    /* cout << "bomba -> "; */
    /* for (int i=0; i <= n; i++) cout << bomba[n] << " "; */
    /* cout << endl; */
    if (n > 1222) cout << "first" << endl;
    else cout << (gn[n] ? "first" : "second") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    calc();
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
