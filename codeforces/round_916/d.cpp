#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pll pair<long long, long long>

void solve () {
    int n; cin >> n;
    vector<pll> a;
    vector<pll> b;
    vector<pll> c;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        a.push_back({num, i});
    }


    for (int i=0; i < n; i++) {
        int num; cin >> num;
        b.push_back({num, i});
    }


    for (int i=0; i < n; i++) {
        int num; cin >> num;
        c.push_back({num, i});
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    vector<int> vis(n + 1);
    int soma = 0;
    int resp = 0;

    // a b c-----------------------------------
    soma += a[0].first;
    vis[a[0].second]++;

    int i = 0;
    while (vis[b[i].second]) {
        i++;
    }

    soma += b[i].first;
    vis[b[i].second]++;


    i = 0;
    while (vis[c[i].second]) {
        i++;
    }

    soma += c[i].first;

    resp = max(resp, soma);
    soma = 0;
    fill(vis.begin(), vis.end(), 0);

    // a c b ---------------------------------------
    soma += a[0].first;
    vis[a[0].second]++;

    i = 0;
    while (vis[c[i].second]) {
        i++;
    }

    soma += c[i].first;
    vis[c[i].second]++;


    i = 0;
    while (vis[b[i].second]) {
        i++;
    }

    soma += b[i].first;

    resp = max(resp, soma);
    soma = 0;
    fill(vis.begin(), vis.end(), 0);
    // b a c ----------------------------

    soma += b[0].first;
    vis[b[0].second]++;

    i = 0;
    while (vis[a[i].second]) {
        i++;
    }

    soma += a[i].first;
    vis[a[i].second]++;


    i = 0;
    while (vis[c[i].second]) {
        i++;
    }

    soma += c[i].first;

    resp = max(resp, soma);
    soma = 0;
    fill(vis.begin(), vis.end(), 0);
    // b c a -------------------------------------------

    soma += b[0].first;
    vis[b[0].second]++;

    i = 0;
    while (vis[c[i].second]) {
        i++;
    }

    soma += c[i].first;
    vis[c[i].second]++;

    i = 0;
    while (vis[a[i].second]) {
        i++;
    }

    soma += a[i].first;

    resp = max(resp, soma);
    soma = 0;
    fill(vis.begin(), vis.end(), 0);
    // c a b ---------------------------

    soma += c[0].first;
    vis[c[0].second]++;

    i = 0;
    while (vis[a[i].second]) {
        i++;
    }

    soma += a[i].first;
    vis[a[i].second]++;

    i = 0;
    while (vis[b[i].second]) {
        i++;
    }

    soma += b[i].first;

    resp = max(resp, soma);
    soma = 0;
    fill(vis.begin(), vis.end(), 0);
    // c b a ---------------------------
    
    soma += c[0].first;
    vis[c[0].second]++;

    i = 0;
    while (vis[b[i].second]) {
        i++;
    }

    soma += b[i].first;
    vis[b[i].second]++;

    i = 0;
    while (vis[a[i].second]) {
        i++;
    }

    soma += a[i].first;

    resp = max(resp, soma);
    soma = 0;
    
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

