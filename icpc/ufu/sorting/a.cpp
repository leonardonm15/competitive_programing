#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<pair<int, string>> arr(n);

    for (int i=0; i < n; i++) {
        string s; cin >> s;
        arr[i] = {s.size(), s};
    }

    sort(arr.rbegin(), arr.rend());

    vector<string> resp;
    for (int i=0; i < n;) {
        vector<string> aux;
        int k = i;
        while (k < n && arr[k].first == arr[i].first) {
            aux.push_back(arr[k].second);
            k++;
        }
        i = k;
        sort(aux.rbegin(), aux.rend());
        for (auto c: aux) resp.push_back(c);
    }

    reverse(resp.begin(), resp.end());
    for (auto c: resp) cout << c << endl;
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
