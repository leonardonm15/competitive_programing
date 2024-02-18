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
    int soma = 1;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
        soma *= num;
    }

    string s; cin >> s;
    vector<int> resp;
    int l = 0;
    int r = s.size() - 1;
    for (int i=0; i < s.size(); i++) {
        if (s[i] == 'L') {
            resp.push_back((soma % k));
            soma /= arr[l];
            l++;
        } else {
            resp.push_back((soma % k));
            soma /= arr[r];
            r--;
        }
    }

    for (auto c: resp) cout << c << " ";
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
