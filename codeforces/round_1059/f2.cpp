#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool inside(int l, int r, int k) {
        return (k >= l && k <= r);
}

void solve () {
    int n, m; cin >> n >> m;

    vector<pair<int, int>> arr;

    vector<int> add(n + 2);
    vector<int> remove(n + 2);

    vector<int> amr(n + 1); // ammount of ranges that goes thru I

    for (int i = 0; i < m; i++) {
            int l, r; cin >> l >> r;
            arr.push_back({l, r});
            add[l]++;
            remove[r + 1]++;
    }

    int now = 0;
    for (int i = 1; i <= n; i++) {
        now -= remove[i];
        now += add[i];

        amr[i] = now;
    }

    vector<int> outsiders;
    for (int i = 1; i <= n; i++) if (!amr[i]) outsiders.push_back(i);

    
    vector<int> out_of_some_range(n + 2, -1);

    for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                    auto [l, r] = arr[j];
                    if (!inside(l, r, i)) {
                            out_of_some_range[i] = j;
                            break;
                    }
            }
    }

    int ir = -1;
    bool outs = false;
    for (int i = 1; i <= n; i++) {
            if (amr[i] == m) {
                    ir = i;
                    outs = false;
                    break;
            }
            if (amr[i] > ir && out_of_some_range[i] != -1) ir = i;
            if (amr[i] > ir && outsiders.size()) {
                    outs = true;
                    ir = i;
            }
    }

    vector<int> resp(n, -1);

    if (amr[ir] == m) {
            resp[ir - 1] = 0;
            int counter = 1;
            for (int i = 0; i < n; i++) if (resp[i] == -1) resp[i] = counter++;

            for (auto v: resp) cout << v << " ";
            cout << endl;
            return;
    }

    int isolate_one = -1;

    cout << "amr -> ";
    for (int i = 1; i <= n; i++) cout << amr[i] << " ";
    cout << endl;

    if (outs) isolate_one = outsiders[0] - 1;
    else {
            cout << "our_of_range -> ";
            for (auto v: out_of_some_range) cout << v << " ";
            cout << endl;

            cout << "Ir -> " << ir << endl;
            isolate_one = arr[out_of_some_range[ir]].first - 1;
    }

    ir--;
    cout << "ir -> " << ir << endl;
    cout << "isolate -> " << isolate_one << endl;
    resp[ir] = 0;
    resp[isolate_one] = 1;

    int counter = 2;
    for (int i = 0; i < n; i++) if (resp[i] == -1) resp[i] = counter++;

    for (auto v: resp) cout << v << " ";
    cout << endl;
}

signed main() {
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
