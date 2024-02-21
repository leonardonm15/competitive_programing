#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }

    string s; cin >> s;
    int l = 0;
    int r = s.size() - 1;
    for (int i=0; i < s.size(); i++) {
        if (l == r) break;
        if (s[i] == 'L') {
            l++;
        } else {
            r--;
        }
    }

    vector<int> resp;
    /* reverse(s.begin(), s.end()); */
    int soma = arr[l] % k;
    resp.push_back(soma);
    for (int i=(int)s.size() - 2; i >= 0; i--) {
        /* cout << "-----------" << endl; */
        /* cout << "l -> " << l << endl; */
        /* cout << "r -> " << r << endl; */
        if (s[i] == 'L') {
            l--;
            soma *= arr[l];
            soma %= k;
        } else {
            r++;
            soma *= arr[r];
            soma %= k;
        }
        resp.push_back(soma);
    }

    reverse(resp.begin(), resp.end());
    for (int i=0; i < resp.size(); i++) cout << resp[i] << " ";
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
