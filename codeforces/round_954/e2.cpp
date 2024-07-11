#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


void solve () {
    int n, k; cin >> n >> k;
    map<int, vector<int>> mod;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        mod[num % k].push_back(num);
    }

    int resp = 0;
    int c = 0;
    for (auto& [m, vec]: mod) {
        sort(vec.rbegin(), vec.rend());

        if (vec.size()&1) {
            c++;

            cout << "vec -> ";
            for (auto cara: vec) cout << cara << " ";
            cout << endl;

            if (c == 2) {
                cout << -1 << endl;
                return;
            }

            if (vec.size() == 1) continue;

            vector<int> pref;
            vector<int> suf;
            int soma = 0;
            int sub = 0;

            for (int i = 1; i < (int)vec.size(); i++) {
                soma += vec[i - 1] - vec[i];
                pref.push_back(soma);
            }
            
            for (int i = (int)vec.size() - 2; i >= 0; i--) {
                sub += vec[i] - vec[i + 1];
                suf.push_back(sub);
            }

            reverse(suf.begin(), suf.end());

            cout << "pref -> ";
            for (auto cara: pref) cout << cara << " ";
            cout << endl;

            cout << "suf -> ";
            for (auto cara: suf) cout << cara << " ";
            cout << endl;
            return;

            int men = 0;
            int r = 1e17;
            for (int i = 1; i < (int)suf.size() - 1; i++) {
                if (!(i&1)) continue;
                int p = pref[i  - 1];
                int s = suf[i];
                cout << "-----------------" << endl;
                cout << "p -> " << p << endl;
                cout << "s -> " << s << endl;
                if (p + s < r) {
                    men = i;
                    r = p + s;
                }
            }

            vec.erase(vec.begin() + men - 1);

            cout << "men -> " << men << endl;
            cout << "r -> " << r << endl;

            cout << "vec -> ";
            for (auto cara: vec) cout << cara << " ";
            cout << endl;

        }
        for (int i = 1; i < vec.size(); i += 2) resp += vec[i - 1] - vec[i];
    }

    cout << resp << endl;
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
