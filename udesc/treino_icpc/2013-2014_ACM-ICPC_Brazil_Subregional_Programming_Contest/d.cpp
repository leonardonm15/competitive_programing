#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> dobra(vector<int> &arr) {
    int n = arr.size();
    vector<int> v(n - (n / 2));
    
    for (int i=0; i < v.size(); i++) {
        v[i] += arr[i];
    }

    int l = v.size() - 1;
    int r = v.size();
    while (r <= arr.size() - 1) {
        v[l] += arr[r];
        l--;
        r++;
    }

    return v;
}

bool brute(vector<int> &arr, vector<int> &ref) {
    
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int soma = 0;
    for (auto &cara: arr) {
        cin >> cara;
        soma += cara;
    }

    int v; cin >> v;
    vector<int> r(v);
    for (auto &cara: r) cin >> cara;


    /* cout << "soma -> " << soma << endl; */
    /* while (arr.size() > 1) { */
    /*     vector<int> k = dobra(arr); */
    /*     cout << "c -> "; */
    /*     for (auto c: k) cout << c << " "; */
    /*     cout << endl; */
    /*     arr = k; */
    /* } */
    /* return; */

    while (arr.size() > 1 && r.size() < (arr.size() - (arr.size() / 2))) {
        /* cout << "arr.size / 2 -> " << arr.size() / 2 << endl; */
        /* cout << "r.size() -> " << r.size() << endl; */
        vector<int> k = dobra(arr);
        cout << "k -> ";
        for (auto cara: k) cout << cara << " ";
        cout << endl;
        arr = k;
    }

    cout << (brute(arr, v) ? 'S' : 'N') << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
