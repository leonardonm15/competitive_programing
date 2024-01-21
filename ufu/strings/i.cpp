#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

void solve(){
    int n; cin >> n;
    map<string, int> cods;
    int par = 0;
    for (ll i = 0; i < n; i++){
        string x; cin >> x;
        char c; cin >> c;
        if (cods[x] >= 1) par = 1;
        else cods[x]++;
    }
    cout << par << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 0;
    if(tc){
        cin >> tc;
        while(tc--) solve();
    } else solve();
    return 0;
}
