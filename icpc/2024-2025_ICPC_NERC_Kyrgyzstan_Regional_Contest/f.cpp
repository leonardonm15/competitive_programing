#include <bits/stdc++.h>
using namespace std;
#define int long long
using T = pair<int,int>;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> a(n+1);
    priority_queue<T, vector<T>, greater<>> pq;
    int s, f; cin >> s >> f;
    for(int i = 0; i < 2*n; i++){
        int b; cin >> b;
        if(i % 2 == 0)
            pq.emplace(b, 1);
        else pq.emplace(b,-1);
    }
    int cont = 0;
    int t = 1;
    while(pq.size()){
        auto [x,y] = pq.top();
        pq.pop();
        if(x <= f && x >= s)a[cont] += x - max(s, t);
        else if(x >= f && t < f)a[cont] += f - t;
        else if(x >= f)break;
        t = x;
        cont += y;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += a[i];
        cout << res << ' ';
    }
    cout << '\n';
}

