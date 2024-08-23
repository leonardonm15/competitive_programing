#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long

void solve(){
    int n,m;cin >> n >> m;
    vector<vector<int>> ar(n,vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ar[i][j];
        }
    }
    
    int res=1;
    for(int i=0;i<n;i++){
        int cont=1;
        for(int j=1;j<m;j++){
            if(abs(ar[i][j]-ar[i][j-1])<=1) cont++;
            else{
                res=max(res,cont);
                cont=1;
            }
        }
        res=max(res,cont);
    }

    for(int i=0;i<m;i++){
        int cont=1;
        for(int j=1;j<n;j++){
            if(abs(ar[j][i]-ar[j-1][i])<=1) cont++;
            else{
                res=max(res,cont);
                cont=1;
            }
        }
        res=max(res,cont);
    }

    cout << res << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
