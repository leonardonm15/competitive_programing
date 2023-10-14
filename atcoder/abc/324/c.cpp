#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> resp;
    for (int i=0; i < n; i++) {
        string r; cin >> r;
        // pega os caras mt grandes ou mt pequenos
        if (r.size() - 1 != s.size() && r.size() > s.size()) continue;
        if (r.size() + 1 != s.size() && r.size() < s.size()) continue;
        // pega os caras com um char 
        bool flag = false;
        int lim = 1;
        /* cout << "r -> "; */
        /* for (int j=0; j < r.size(); j++) cout << r[j]; */
        /* cout << endl; */

        if (r.size() > s.size()) {
            if (r[r.size()] != s[s.size()]) {
                r.erase(s.size(), 1);
                flag = true;
                lim--;
            }
            for (int j=0; j < s.size() && !flag; j++) {
                if (r[j] != s[j]) {
                    r.erase(j, 1);
                    lim--;
                    break;
                }
            }
        }
        // cout << "r size -> " << r.size() << endl;
        flag = false;
        /* cout << "r -> "; */
        /* for (int j=0; j < r.size(); j++) cout << r[j]; */
        /* cout << endl; */ 
        if (r.size() < s.size()) {
            if (r[r.size()] != s[s.size()]) {
                r.push_back(s.size());
                flag = true; 
                lim--;
            }
            for (int j=0; j < s.size() && !flag; j++) {
                if (r[j] != s[j]) {
                    r.insert(j, string(1, s[j]));
                    lim--;
                    break;
                }
            }
        }
        /* cout << "r dps do insert -> " << r << endl; */
        /* for (int j=0; j < r.size(); j++) cout << r[j] << " "; */
        /* cout << endl; */
        // caso troca um char
        int diff = 0;
        for (int j=0; j < r.size(); j++) {
            if (s[j] != r[j]) {
                diff++;
            }
            if (diff > 1) break;
        }
        int num = i;
        num++;
        if (diff > lim) continue;
        else resp.push_back(num);
    }
    cout << resp.size() << endl;
    for (auto cara: resp) cout << cara << " ";
    cout << endl;
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
