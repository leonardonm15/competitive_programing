#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    vector<int> h(n);
    
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) cin >> h[i];
    
    vector<int> arr;
    int resp = 0;
    for (int i=0; i < n; i++) {
        if (arr.size() == 0 || arr[arr.size() - 1] % h[i] == 0) arr.push_back(v[i]);
        else {
            int sum = 0;
            vector<int> p;
            p.push_back(0);

            cout << "arr -> ";
            for (auto cara: arr) cout << cara << " ";
            cout << endl;

            for (int j=0; j < arr.size(); j++) {
                sum += v[j];
                p.push_back(sum);
            }

            for (int j=0; j < arr.size(); j++) {
                int idx = lower_bound(p.begin(), p.end(), arr[j] + k) - p.begin();
                resp = max(resp, idx - j + 1);
            }

            arr.clear();
            arr.push_back(v[i]);
        }
        
    }

    if (arr.size() > 0) {
        int sum = 0;
        vector<int> p;
        p.push_back(0);

        cout << "arr -> ";
        for (auto cara: arr) cout << cara << " ";
        cout << endl;

        for (int j=0; j < arr.size(); j++) {
            sum += v[j];
            p.push_back(sum);
        }

        for (int j=0; j < arr.size(); j++) {
            int idx = lower_bound(p.begin(), p.end(), arr[j] + k) - p.begin();
            resp = max(resp, idx - j + 1);
        }
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
