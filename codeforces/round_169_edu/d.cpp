#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<string> vec;
vector<char> f(4);

void normalize(string &s) {
    if ((int) s[1] < (int) s[0]) swap(s[1], s[0]);
}

bool inrange(int a, int n) {
    if (a >= 0 && a < n) return true;
    else return false;
}

int min_path(string su, bool left, map<string, vector<int>> &where, int u, int v) {
    int resp = 1e18;
    for (int i = 0; i < 4; i++) {
        
        string l;
        if (left) {
            l += su[0];
            l += f[i];
        } else {
            l += f[i];
            l += su[1];
        }

        if (f[i] == su[0] || l == su) continue;

        normalize(l);
        int sz = where[l].size();

        if (sz) {
            vector<int> &arr = where[l];

            int lbi = lower_bound(arr.begin(), arr.end(), v) - arr.begin();
            int upbi = upper_bound(arr.begin(), arr.end(), v) - arr.begin();
            lbi--;

            int ansl = 1e18; // resp lower_bound
            int ansu = 1e18; // resp upper_bound

            if (l == vec[v]) {
                ansl = abs(u - v);
                ansu = abs(u - v);
            } else {
                if (inrange(lbi, sz)) ansl = abs(u - arr[lbi]) + abs(arr[lbi] - v);
                if (inrange(upbi, sz)) ansu = abs(u - arr[upbi]) + abs(arr[upbi] - v);
            }

            resp = min({resp, ansl, ansu});
        }
    }

    return resp;
}

int tc = 0;
void solve () {
    int n, q; cin >> n >> q;

    map<string, vector<int>> where;


    f[0] = 'B';
    f[1] = 'G';
    f[2] = 'R';
    f[3] = 'Y';


    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        normalize(s);
        vec.push_back(s);
        where[s].push_back(i);
    }

    while (q--) {
        tc++;
        int u, v; cin >> u >> v;
        u--; v--;
        string su = vec[u];
        string sv = vec[v];
        int resp = 1e18;

        if (su == sv) {
            cout << abs(u - v) << endl;
            continue;
        }

        int right_letter = min_path(su, false, where, u, v);
        int left_letter = min_path(su, true, where, u, v);
        resp = min(right_letter, left_letter);

        cout << (resp == (int)1e18 ? -1 : resp) << endl;
    }

    vec.clear();
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
