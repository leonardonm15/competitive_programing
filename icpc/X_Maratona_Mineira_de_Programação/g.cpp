#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin >> n;
    int res=2;
    for(int i=0;i<n;i++){
        int a,b;cin >> a >> b;
        if(a==res) swap(b,res);
        else if(b==res) swap(a,res);
    }
    cout << res << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
