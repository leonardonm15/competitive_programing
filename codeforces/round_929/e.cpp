#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int gauss(int u, int d) {
    int f = u - min(d, u);
    if (d > u) {

    }
    return;
}


void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> pref;
    int sum = 0;
    pref.push_back(0);
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        pref.push_back(sum);
    }

    cout << "pref -> ";
    for (auto cara: pref) cout << cara << " ";
    cout << endl;

    int q; cin >> q;
    while (q--) {
        int l, u; cin >> l >> u;
        int ele = l;
        int r = pref.size() - 1;
        int resp = 1e9 + 5;
        int mx = pref[ele - 1] + u;
        int cur_sum = 0;
        cout << "---------" << endl;
        cout << "max -> " << mx << endl;
        while (l <= r) {
            /* cout << "============" << endl; */
            int mid = (l + r) >> 1;
            int cur = pref[mid] - pref[ele - 1];
            /* cout << "soma atual -> " << cur << endl; */
            if (cur > mx) {
                r = mid - 1;
            } else {
                cout << "potencial resposta -> " << mid << endl;
                // o quao perto ta do perfeito é o quao perto ta do U
                int k = abs(cur - u);
                if (cur > cur_sum || cur_sum == 1e9 + 5) {
                    resp = mid;
                    cur_sum = cur;
                }
                if ((cur > cur_sum && mid > resp) || (cur == cur_sum && mid < resp)) {
                    resp = mid;
                    cur_sum = cur;
                }
                /* else resp = min(resp, mid); */
                /* cout << "resp -> " << resp << endl; */
                l = mid + 1;
            }
        }

        cout << resp << endl;
    }
    cout << endl;
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
