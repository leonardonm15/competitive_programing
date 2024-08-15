#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 310000;
vector<int> sigma(maxn,1);

void solve() {
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        string res;
        bool ok = 0;
        if(a==sigma[sigma[a]] && sigma[a]!=a){
            res += "romantico ";
            ok = 1;
        }
        if(sigma[a]>a){
            res += "abundante";
            ok = 1;
        }
        if(sigma[a]==a){
            res += "perfecto";
            ok = 1;
        }
        if(!ok)
            res += "complicado";
        cout << a << " " << res << endl;
    }
}

signed main() {
    for(int i = 2; i < maxn; i++){
        for(int j = 2*i; j<maxn;j+=i)
            sigma[j]+=i;
    }
    sigma[1]=0;
    sigma[0]=0;

    solve();
}
