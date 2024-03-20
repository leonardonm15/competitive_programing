#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i=1; i <= n; i++) cin >> arr[i];
    vector<string> resp;

    int mid = (1 + n) / 2;
    /* cout << "mid -> " << mid << endl; */

    if (n > 2) {
        if (arr[1] == k) {
            string s = "1 ";
            s += to_string(mid);
            resp.push_back(s);
            swap(arr[mid] , arr[1]);
        } else if (arr[n] == k) {
            string s;
            s += to_string(n);
            s += " ";
            s += to_string(mid);
            resp.push_back(s);
            swap(arr[mid], arr[n]);
        }
    }

    if (trade != 1e9 + 5) {
        string s;
        s += to_string(mid);
        s += " ";
        s += to_string(trade);
        resp.push_back(s);
    }

    if (arr[1] > arr[n]) {
        string s;
        s += "1 ";
        s += to_string(n);
        resp.push_back(s);
    }

    int trade = 1e9 + 5;
    for (int i=1; i <= n; i++) {
        if (arr[i] == k && i != mid) {
            trade = i;
        }
    }


    cout << resp.size() << endl;
    for (auto cara: resp) cout << cara << endl;
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
