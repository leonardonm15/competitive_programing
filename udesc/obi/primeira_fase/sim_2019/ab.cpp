#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    int res = 1, cont = 0;
    for(int i = 1; i  <= n; i++){
        for(int j = 1; j <= n; j++){
            int evil = v[j];
            for(int g = 1; g <= n; g++){
                if(g < n && v[g] == evil && v[g] != v[g+1]){
                    if(evil == v[j] && v[g] == v[i]){
                        cont++;
                        evil = v[i];
                    }
                    else if(evil == v[i] && v[g] == v[j]){
                        cont++;
                        evil = v[j];
                    }
                }
                else if(g < n && v[g] == evil && v[g+1] == evil){
                    cont = 0;
                    break;
                }
            }
            if(cont > res){
                res = cont;
            }
            cont = 0;
        }
    }
    cout << res << endl;

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
