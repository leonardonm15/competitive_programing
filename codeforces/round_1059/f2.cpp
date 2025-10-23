#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool inside(int l, int r, int k) {
        return (k >= l && k <= r);
}

int check(vector<pair<int, int>> &v, vector<int> &arr) {
    int n = arr.size();
    vector<int> mex(n + 2);

    for (auto [l, r]: v) {
        vector<int> mx(n + 2);
        for (int i = l - 1; i <= r - 1; i++) {
            mx[arr[i]]++;
        }

        int mexi = 0;
        for (int i = 0; i <= n + 1; i++) {
            if (mx[i] == 0) {
                mexi = i;
                break;
            }
        }

        mex[mexi]++;
    }

    for (int i = 0; i <= n + 1; i++) {
        if (mex[i] == 0) {
            return i;
        }
    }

    return n + 1;
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

    /* if (tc == 122) { */
    /*     cout << n << "$" << m << "%"; */
    /*     for (auto [l, r]: arr) { */
    /*         cout << l << "#" << r << "%"; */
    /*     } */
    /*     cout << endl; */
    /* } */

    vector<int> resp(n, -1);
    int now = 0;
    int r = -1;
    for (int i = 1; i <= n; i++) {
        now -= remove[i];
        now += add[i];

        amr[i] = now;
        if (amr[i] == m) {
            r = i - 1;
        }

    }


    if (r != -1) {
        resp[r] = 0;
        int counter = 1;
        for (int i = 0; i < n; i++) {
            if (resp[i] == -1) resp[i] = counter++;
        }

        for (auto v: resp) cout << v << " ";
        cout << endl;

        return;
    } 


    vector<int> start(n + 1), end(n + 1);
    for (int i = 0; i < m; i++) {
        auto [l, r] = arr[i];
        start[l]++;
        end[r]++;
    }

    int iesc = -1;
    for (int i = 1; i <= n; i++) {
        if (!start[i] || !end[i]) iesc = i;
    }

    int counter = 0;
    bool antes = true ^ (iesc == 1);
    bool depois = true ^ (iesc == n);
    for (auto [l, r]: arr) {
        if (inside(l, r, iesc) == 1) {
            if (inside(l, r, iesc + 1) == 0)  depois = false;
            if (inside(l, r, iesc - 1) == 0) antes = false;
        }
    }

    /* for (int i = 2; i <= n; i++) { */
    /*     for (auto [l, r]: arr) { */
    /*         if (inside(l, r, i) == 1) { */
    /*             if (inside(l, r, i - 1)) ante */
    /*         } */
    /*     } */
    /* } */


    if (antes && iesc > -1) {
        resp[iesc - 1] = counter++;
        resp[iesc - 2] = counter++;
    } else if (depois && iesc > -1) {
        resp[iesc - 1] = counter++;
        resp[iesc] = counter++;
    } else {
        resp[0] = 0;
        resp[1] = 2;
        resp[2] = 1;

        counter = 3;
    }


    for (int i = 0; i < n; i++) if (resp[i] == -1) resp[i] = counter++;

    for (auto v: resp) cout << v << " ";
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
