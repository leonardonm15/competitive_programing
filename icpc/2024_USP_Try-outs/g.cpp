#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e3+5;
int inf = 1e17;
int dp[maxn][maxn];
int a[maxn];
int n;

int bp(int i, int tp){
    if(i == n)return 0;
    if(dp[i][tp] != inf){
        return dp[i][tp];
    }
    int p1 = abs(a[tp] - a[i+1]);
    int p2 = abs(a[i+1] - a[i]);

    return dp[i][tp] = min(bp(i+1,tp) + p2, bp(i+1, i) + p1);
    

}

signed main(){
    cin >> n;
    a[0] = 0;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = inf;
        }
    }
    bp(0,0);
    cout << dp[0][0] << '\n';
}
