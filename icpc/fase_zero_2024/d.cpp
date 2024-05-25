#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAX = 2e5 + 2;
const int INF = 1.05e9;
const int INFM = -1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

void solve(){
    ll e, v; cin >> e >> v;
    ll h = e/v;
    float vv = v;
    float res = e%v;
    float m = (res/vv)*60;
    h += 19;
    h %= 24;
    if(h < 10){
        cout << "0" << h << ":";
        if(m < 10){
            cout << 0 << int(m) << endl;
        }else{
            cout << int(m) << endl;
        }
    }else{
        cout << h << ":";
        if(m < 10){
            cout << 0 << int(m) << endl;
        }else{
            cout << int(m) << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    bool tttt = 0;
    if(tttt){
        int testcase; cin >> testcase;
        while (testcase--){
            solve();
        }
    }else solve();

    return 0;
}

