#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;


void solve () {
    int n, d; cin >> n >> d;
    vector<pair<int, int>> arr;
    arr.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        int x, v; cin >> x >> v;
        arr.push_back({x, v});
    }

    sort(arr.begin(), arr.end());

    vector<int> groups;

    int soma = arr[1].second;
    for (int i = 2; i <= n; i++) {
        auto [f, s] = arr[i];
        auto [pf, ps] = arr[i - 1];
        if (f - pf > d) {
            groups.push_back(soma);
            soma = s;
        } else {
            soma += s;
        }

    }

    cout << "arr -> ";
    for (auto [a, b]: arr) cout << "[" << a << " " << b << "] - ";
    cout << endl;


    int resp = 0;
    groups.push_back(soma);
    groups.push_back(0);

    /* cout << "groups -> "; */
    /* for (auto v: groups) cout << v << " "; */
    /* cout << endl; */

    sort(groups.rbegin(), groups.rend());
    resp = groups[0] + groups[1];

    /* groups.clear(); */

    /* soma = 0; */
    /* for (int i = n - 1; i >= 0; i--) { */
    /*     auto [f, s] = arr[i]; */
    /*     auto [pf, ps] = arr[i + 1]; */
    /*     if (pf - f > d) { */
    /*         groups.push_back(soma); */
    /*         soma = s; */
    /*     } else { */
    /*         soma += s; */
    /*     } */
    /* } */

    /* groups.push_back(soma); */
    /* groups.push_back(0); */

    /* sort(groups.rbegin(), groups.rend()); */

    /* resp = max(resp, groups[0] +  groups[1]); */
    
    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
