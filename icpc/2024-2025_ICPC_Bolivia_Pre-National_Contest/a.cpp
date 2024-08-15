#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int a,b,c,delta;

int eval(int x){
    return 2*a*x*x*x+3*b*x*x+6*c*x;
}

int sqrtInt(int x){
    int l = 1, r = x;
    while(l<r){
        int m = (l+r)/2;
        if(m*m<x)
            l = m;
        else if (m*m>x)
            r = m;
        else return m;
    }
    return l;
}

int root(int pos){
    return (-b + pos*sqrtInt(delta))/(2*a);
}

void solve() {
    int l,r;
    cin >> a >> b >> c >> l >> r;
    delta = b*b-4*a*c;
    int res;
    if(delta > 0){
        int r1 = root(-1);
        int r2 = root(1);
        if(l<r1 && r1<r && l<r2 && r2<r)
            res = abs(eval(r) - eval(r2)) + abs(eval(r2) - eval(r1)) + abs(eval(r1) - eval(l));
        else if(l<r2 && r2<r)
            res = abs(eval(r2)-eval(l))+abs(eval(r)-eval(r2));
        else if(l<r1 && r1<r)
            res = abs(eval(r1)-eval(l))+abs(eval(r)-eval(r1));
        else
            res = abs(eval(r)-eval(l));

    }else{
        res = abs(eval(r) - eval(l));
    }
    int d = 6;
    if(res%2==0){
        res /=2;
        d /=2;
    }
    if(res%3==0){
        res /=3;
        d /=3;
    }
    cout << res << '/' << d << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}
