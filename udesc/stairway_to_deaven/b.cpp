#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<int> quantas_eu_dependo, quantas_dependem_de_mim;
vector<int> arr;
map<string, int> mp;

bool cmp(int a, int b) {
    if (quantas_dependem_de_mim[a] < quantas_dependem_de_mim[b]) return true;
    if (quantas_dependem_de_mim[a] == quantas_dependem_de_mim[b]) {
        if (quantas_eu_dependo[a] < quantas_eu_dependo[b]) return true;
        if (quantas_eu_dependo[a] == quantas_eu_dependo[b]) return a > b;
    }

    return false;
}   

void solve () {
    int n; cin >> n;
    vector<string> c;
    quantas_eu_dependo.resize(n);
    quantas_dependem_de_mim.resize(n);

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        arr.push_back(i);
        c.push_back(s);

        int m; cin >> m;
        quantas_eu_dependo[i] = m;

        for (int j = 0; j < m; j++) {
            int k; cin >> k;
            k--;
            quantas_dependem_de_mim[k]++;
        }
    }

    sort(arr.begin(), arr.end(), cmp);
    
    int m = (n * 25) / 100;

    for (int i = 0; i < m; i++) cout << c[arr[i]] << endl;

}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
