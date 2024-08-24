#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a.begin(), a.end());
    int pr = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(a[i] * (n-i) > res){
            res = a[i] * (n-i);
            pr = a[i];
        }
    }
    cout << pr << ' ' << res << '\n';

}
