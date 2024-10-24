#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int bb(vector<int>& arr, int tg) {
    int l = 0;
    int r = (int)arr.size() - 1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (arr[mid] < tg) {
            ans = arr[mid];
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

void solve () {
    int n; cin >> n;
    vector<int> arr;
    vector<int> pref;
    map<int, vector<int>> mp;

    pref.push_back(0);
    int soma = 0;
    mp[0].push_back(0);

    int lastap = -1;
    int resp = 0;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        if (num == 0) {
            resp++;
            lastap = i;
            mp[soma].push_back(i);
            pref.push_back(soma);
            continue;
        }

        soma += num;
        pref.push_back(soma);

        /* if (soma == 0) { */
        /*     resp++; */
        /*     lastap = i; */
        /* } */

        /* cout << "------------" << endl; */
        /* cout << "soma -> " << soma << endl; */

        if (soma == 0) {
            int last0 = mp[0][mp[0].size() - 1];
            if (last0 + 1 > lastap) {
                resp++;
                lastap = i;
            }
        }

        if (mp[soma].size() > 0) {
            int k = bb(mp[soma], i);
            if (k != -1 && k + 1 > lastap) {
                resp++;
                lastap = i;
            }
        }

        mp[soma].push_back(i);
    }

    cout << resp << endl;

    /* cout << "pref -> "; */
    /* for (auto c: pref) cout << c << " "; */
    /* cout << endl; */
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
